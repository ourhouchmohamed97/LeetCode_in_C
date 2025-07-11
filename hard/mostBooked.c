// Meeting Rooms III

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long time;
    int room;
} RoomEnd;

typedef struct {
    long long start;
    long long end;
    long long original_start;
} Meeting;

// Min-heap for RoomEnd (based on time and room number)
typedef struct {
    RoomEnd *data;
    int size;
    int capacity;
} MinHeapRooms;

// Min-heap for available rooms (based on room number)
typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeapAvailable;

void initMinHeapRooms(MinHeapRooms *heap, int capacity) {
    heap->data = (RoomEnd *)malloc(capacity * sizeof(RoomEnd));
    heap->size = 0;
    heap->capacity = capacity;
}

void initMinHeapAvailable(MinHeapAvailable *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void swapRoomEnd(RoomEnd *a, RoomEnd *b) {
    RoomEnd temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushRoomEnd(MinHeapRooms *heap, RoomEnd item) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (RoomEnd *)realloc(heap->data, heap->capacity * sizeof(RoomEnd));
    }
    heap->data[heap->size] = item;
    int current = heap->size;
    heap->size++;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap->data[parent].time > heap->data[current].time || 
            (heap->data[parent].time == heap->data[current].time && heap->data[parent].room > heap->data[current].room)) {
            swapRoomEnd(&heap->data[parent], &heap->data[current]);
            current = parent;
        } else {
            break;
        }
    }
}

RoomEnd popRoomEnd(MinHeapRooms *heap) {
    RoomEnd result = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;
        if (left < heap->size && (heap->data[left].time < heap->data[smallest].time || 
            (heap->data[left].time == heap->data[smallest].time && heap->data[left].room < heap->data[smallest].room))) {
            smallest = left;
        }
        if (right < heap->size && (heap->data[right].time < heap->data[smallest].time || 
            (heap->data[right].time == heap->data[smallest].time && heap->data[right].room < heap->data[smallest].room))) {
            smallest = right;
        }
        if (smallest != current) {
            swapRoomEnd(&heap->data[current], &heap->data[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
    return result;
}

void pushAvailable(MinHeapAvailable *heap, int item) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int *)realloc(heap->data, heap->capacity * sizeof(int));
    }
    heap->data[heap->size] = item;
    int current = heap->size;
    heap->size++;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap->data[parent] > heap->data[current]) {
            swapInt(&heap->data[parent], &heap->data[current]);
            current = parent;
        } else {
            break;
        }
    }
}

int popAvailable(MinHeapAvailable *heap) {
    int result = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;
        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }
        if (smallest != current) {
            swapInt(&heap->data[current], &heap->data[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
    return result;
}

int compareMeetings(const void *a, const void *b) {
    Meeting *meetingA = (Meeting *)a;
    Meeting *meetingB = (Meeting *)b;
    if (meetingA->original_start < meetingB->original_start) return -1;
    if (meetingA->original_start > meetingB->original_start) return 1;
    return 0;
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    Meeting *sortedMeetings = (Meeting *)malloc(meetingsSize * sizeof(Meeting));
    for (int i = 0; i < meetingsSize; i++) {
        sortedMeetings[i].start = meetings[i][0];
        sortedMeetings[i].end = meetings[i][1];
        sortedMeetings[i].original_start = meetings[i][0];
    }
    qsort(sortedMeetings, meetingsSize, sizeof(Meeting), compareMeetings);

    MinHeapAvailable availableRooms;
    initMinHeapAvailable(&availableRooms, n);
    for (int i = 0; i < n; i++) {
        pushAvailable(&availableRooms, i);
    }

    MinHeapRooms occupiedRooms;
    initMinHeapRooms(&occupiedRooms, meetingsSize);

    int *roomCount = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < meetingsSize; i++) {
        long long currentTime = sortedMeetings[i].original_start;
        // Check if any occupied rooms have ended by currentTime
        while (occupiedRooms.size > 0 && occupiedRooms.data[0].time <= currentTime) {
            RoomEnd freedRoom = popRoomEnd(&occupiedRooms);
            pushAvailable(&availableRooms, freedRoom.room);
        }
        if (availableRooms.size > 0) {
            int room = popAvailable(&availableRooms);
            roomCount[room]++;
            RoomEnd newEnd;
            newEnd.time = sortedMeetings[i].end;
            newEnd.room = room;
            pushRoomEnd(&occupiedRooms, newEnd);
        } else {
            // Need to delay the meeting until the earliest end time
            RoomEnd earliestEnd = popRoomEnd(&occupiedRooms);
            long long delay = earliestEnd.time - currentTime;
            long long newEndTime = earliestEnd.time + (sortedMeetings[i].end - sortedMeetings[i].start);
            roomCount[earliestEnd.room]++;
            RoomEnd newEnd;
            newEnd.time = newEndTime;
            newEnd.room = earliestEnd.room;
            pushRoomEnd(&occupiedRooms, newEnd);
        }
    }

    free(sortedMeetings);
    free(availableRooms.data);
    free(occupiedRooms.data);

    int maxMeetings = -1;
    int resultRoom = 0;
    for (int i = 0; i < n; i++) {
        if (roomCount[i] > maxMeetings) {
            maxMeetings = roomCount[i];
            resultRoom = i;
        } else if (roomCount[i] == maxMeetings && i < resultRoom) {
            resultRoom = i;
        }
    }
    free(roomCount);
    return resultRoom;
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