// Meeting Rooms III

#include <stdlib.h>

typedef struct {
    long long end;
    int room;
} BusyRoom;

/* Min-heap for available rooms */
void swapInt(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

void heapPushAvail(int* heap, int* size, int val) {
    int i = (*size)++;
    heap[i] = val;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swapInt(&heap[p], &heap[i]);
        i = p;
    }
}

int heapPopAvail(int* heap, int* size) {
    int res = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < *size && heap[l] < heap[s]) s = l;
        if (r < *size && heap[r] < heap[s]) s = r;
        if (s == i) break;
        swapInt(&heap[i], &heap[s]);
        i = s;
    }
    return res;
}

/* Min-heap for busy rooms (by end time, then room number) */
void swapBusy(BusyRoom* a, BusyRoom* b) {
    BusyRoom t = *a; *a = *b; *b = t;
}

void heapPushBusy(BusyRoom* heap, int* size, BusyRoom val) {
    int i = (*size)++;
    heap[i] = val;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].end < heap[i].end ||
           (heap[p].end == heap[i].end && heap[p].room < heap[i].room))
            break;
        swapBusy(&heap[p], &heap[i]);
        i = p;
    }
}

BusyRoom heapPopBusy(BusyRoom* heap, int* size) {
    BusyRoom res = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < *size &&
           (heap[l].end < heap[s].end ||
           (heap[l].end == heap[s].end && heap[l].room < heap[s].room)))
            s = l;
        if (r < *size &&
           (heap[r].end < heap[s].end ||
           (heap[r].end == heap[s].end && heap[r].room < heap[s].room)))
            s = r;
        if (s == i) break;
        swapBusy(&heap[i], &heap[s]);
        i = s;
    }
    return res;
}

int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), cmp);

    int* available = malloc(sizeof(int) * n);
    int availSize = 0;

    BusyRoom* busy = malloc(sizeof(BusyRoom) * n);
    int busySize = 0;

    int* count = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        heapPushAvail(available, &availSize, i);

    for (int i = 0; i < meetingsSize; i++) {
        long long start = meetings[i][0];
        long long end = meetings[i][1];
        long long duration = end - start;

        while (busySize > 0 && busy[0].end <= start) {
            BusyRoom br = heapPopBusy(busy, &busySize);
            heapPushAvail(available, &availSize, br.room);
        }

        if (availSize > 0) {
            int room = heapPopAvail(available, &availSize);
            heapPushBusy(busy, &busySize, (BusyRoom){end, room});
            count[room]++;
        } else {
            BusyRoom br = heapPopBusy(busy, &busySize);
            long long newEnd = br.end + duration;
            heapPushBusy(busy, &busySize, (BusyRoom){newEnd, br.room});
            count[br.room]++;
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (count[i] > count[ans])
            ans = i;
    }

    free(available);
    free(busy);
    free(count);
    return ans;
}

int main() {
    // Test Case 1
    int n1 = 2;
    int meetings1[][2] = {{0,10},{1,5},{2,7},{3,4}};
    int* meetingsPtr1[] = {meetings1[0], meetings1[1], meetings1[2], meetings1[3]};
    int meetingsSize1 = 4;
    int meetingsColSize1[] = {2,2,2,2};
    int result1 = mostBooked(n1, meetingsPtr1, meetingsSize1, meetingsColSize1);
    printf("Test Case 1: %d (Expected: 0)\n", result1);

    // Test Case 2
    int n2 = 3;
    int meetings2[][2] = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    int* meetingsPtr2[] = {meetings2[0], meetings2[1], meetings2[2], meetings2[3], meetings2[4]};
    int meetingsSize2 = 5;
    int meetingsColSize2[] = {2,2,2,2,2};
    int result2 = mostBooked(n2, meetingsPtr2, meetingsSize2, meetingsColSize2);
    printf("Test Case 2: %d (Expected: 1)\n", result2);

    // Test Case 3
    int n3 = 10;
    int meetings3[][2] = {{1,300001},{2,300002},{3,300003},{4,300004},{5,300005},{6,300006},{7,300007},{8,300008},{9,300009},{10,300010},{11,300011},{12,300012},{13,300013},{14,300014},{15,300015},{16,300016},{17,300017},{18,300018},{19,300019},{20,300020},{21,300021},{22,300022},{23,300023},{24,300024},{25,300025},{26,300026},{27,300027},{28,300028},{29,300029},{30,300030},{31,300031},{32,300032}};
    int* meetingsPtr3[32];
    for (int i = 0; i < 32; i++) {
        meetingsPtr3[i] = meetings3[i];
    }
    int meetingsSize3 = 32;
    int meetingsColSize3[32];
    for (int i = 0; i < 32; i++) {
        meetingsColSize3[i] = 2;
    }
    int result3 = mostBooked(n3, meetingsPtr3, meetingsSize3, meetingsColSize3);
    printf("Test Case 3: %d (Expected: 0)\n", result3);

    return 0;
}