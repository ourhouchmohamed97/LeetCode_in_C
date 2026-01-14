// Separate Squares II

typedef long long ll;

typedef struct {
    ll y;
    int event_type;
    ll x_left;
    ll x_right;
} Event;

typedef struct {
    ll x_left;
    ll x_right;
} Interval;

typedef struct {
    ll start_y;
    ll height;
    ll width;
} Slice;

static int cmpEvent(const void* a, const void* b) {
    const Event* ea = (const Event*)a;
    const Event* eb = (const Event*)b;
    if (ea->y < eb->y) return -1;
    if (ea->y > eb->y) return 1;
    if (ea->event_type < eb->event_type) return -1;
    if (ea->event_type > eb->event_type) return 1;
    if (ea->x_left < eb->x_left) return -1;
    if (ea->x_left > eb->x_left) return 1;
    if (ea->x_right < eb->x_right) return -1;
    if (ea->x_right > eb->x_right) return 1;
    return 0;
}

static int cmpInterval(const void* a, const void* b) {
    const Interval* ia = (const Interval*)a;
    const Interval* ib = (const Interval*)b;
    if (ia->x_left < ib->x_left) return -1;
    if (ia->x_left > ib->x_left) return 1;
    if (ia->x_right < ib->x_right) return -1;
    if (ia->x_right > ib->x_right) return 1;
    return 0;
}

static ll union_width(Interval* intervals, int intervalsSize) {
    qsort(intervals, intervalsSize, sizeof(Interval), cmpInterval);

    ll total_width = 0;
    ll rightmost = (ll)-1e18;

    for (int i = 0; i < intervalsSize; i++) {
        ll left = intervals[i].x_left;
        ll right = intervals[i].x_right;
        if (left > rightmost) {
            total_width += right - left;
            rightmost = right;
        } else if (right > rightmost) {
            total_width += right - rightmost;
            rightmost = right;
        }
    }
    return total_width;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    (void)squaresColSize;

    Event* events = (Event*)malloc(sizeof(Event) * (2 * squaresSize));
    int eventsSize = 0;

    for (int i = 0; i < squaresSize; i++) {
        ll x = squares[i][0];
        ll y = squares[i][1];
        ll length = squares[i][2];
        events[eventsSize++] = (Event){y, 1, x, x + length};
        events[eventsSize++] = (Event){y + length, -1, x, x + length};
    }

    qsort(events, eventsSize, sizeof(Event), cmpEvent);

    Interval* active_intervals = (Interval*)malloc(sizeof(Interval) * eventsSize);
    int activeSize = 0;

    Slice* horizontal_slices = (Slice*)malloc(sizeof(Slice) * eventsSize);
    int slicesSize = 0;

    ll prev_y = events[0].y;
    ll total_area = 0;

    for (int i = 0; i < eventsSize; i++) {
        ll y = events[i].y;
        int event_type = events[i].event_type;
        ll x_left = events[i].x_left;
        ll x_right = events[i].x_right;

        if (y > prev_y && activeSize > 0) {
            ll height = y - prev_y;

            Interval* tmp = (Interval*)malloc(sizeof(Interval) * activeSize);
            for (int k = 0; k < activeSize; k++) tmp[k] = active_intervals[k];
            ll width = union_width(tmp, activeSize);
            free(tmp);

            horizontal_slices[slicesSize++] = (Slice){prev_y, height, width};
            total_area += height * width;
        }

        if (event_type == 1) {
            active_intervals[activeSize++] = (Interval){x_left, x_right};
        } else {
            for (int k = 0; k < activeSize; k++) {
                if (active_intervals[k].x_left == x_left && active_intervals[k].x_right == x_right) {
                    active_intervals[k] = active_intervals[--activeSize];
                    break;
                }
            }
        }

        prev_y = y;
    }

    double half = (double)total_area / 2.0;
    double accumulated = 0.0;

    for (int i = 0; i < slicesSize; i++) {
        ll start_y = horizontal_slices[i].start_y;
        ll height = horizontal_slices[i].height;
        ll width = horizontal_slices[i].width;

        double slice_area = (double)height * (double)width;
        if (accumulated + slice_area >= half) {
            double ans = (double)start_y + (half - accumulated) / (double)width;
            free(events);
            free(active_intervals);
            free(horizontal_slices);
            return ans;
        }
        accumulated += slice_area;
    }

    double ret = (double)prev_y;
    free(events);
    free(active_intervals);
    free(horizontal_slices);
    return ret;
}