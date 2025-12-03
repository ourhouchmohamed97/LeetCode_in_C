// Count Number of Trapezoids II

#include <stdlib.h>
#include <math.h>

typedef struct {
    long long dx;
    long long dy;
    long long c;
} Segment;

// calculate GCD
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Compare for sorting segments
int compareSegments(const void* a, const void* b) {
    Segment* sa = (Segment*)a;
    Segment* sb = (Segment*)b;
    
    if (sa->dx != sb->dx) return (sa->dx > sb->dx) ? 1 : -1;
    if (sa->dy != sb->dy) return (sa->dy > sb->dy) ? 1 : -1;
    if (sa->c != sb->c) return (sa->c > sb->c) ? 1 : -1;
    return 0;
}

int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize < 4) return 0;

    int maxSegments = pointsSize * (pointsSize - 1) / 2;
    Segment* segments = (Segment*)malloc(sizeof(Segment) * maxSegments);
    
    // Phase 1: Count based on slope
    // Finds all pairs of parallel segments 
    // Non parallelogram trapezoids contribute 1, parallelograms contribute 2
    int k = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            long long dx = points[j][0] - points[i][0];
            long long dy = points[j][1] - points[i][1];
            
            // Normalize for slope(divide by GCD)
            long long common = gcd(llabs(dx), llabs(dy));
            dx /= common;
            dy /= common;
            
            // Canonicalize direction
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            
            long long c = dy * points[i][0] - dx * points[i][1];
            
            segments[k].dx = dx;
            segments[k].dy = dy;
            segments[k].c = c;
            k++;
        }
    }

    qsort(segments, k, sizeof(Segment), compareSegments);

    int totalTrapezoids = 0;
    
    for (int i = 0; i < k; ) {
        int j = i;
        int currentSlopeCount = 0; 
        
        while (j < k && segments[i].dx == segments[j].dx && segments[i].dy == segments[j].dy) {
            int l = j;
            while (l < k && segments[i].dx == segments[l].dx && 
                            segments[i].dy == segments[l].dy && 
                            segments[j].c == segments[l].c) {
                l++;
            }
            
            int countOnThisLine = l - j;
            totalTrapezoids += currentSlopeCount * countOnThisLine;
            currentSlopeCount += countOnThisLine;
            j = l;
        }
        i = j;
    }

    // Phase 2: Count vector matches 
    // Counts pairs of segments with same slope and length
    // Each geometric parallelogram contributes 2 to this count
    k = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            long long dx = points[j][0] - points[i][0];
            long long dy = points[j][1] - points[i][1];
            
            
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            
            
            long long c = dy * points[i][0] - dx * points[i][1];
            
            segments[k].dx = dx;
            segments[k].dy = dy;
            segments[k].c = c;
            k++;
        }
    }
    
    qsort(segments, k, sizeof(Segment), compareSegments);
    
    int parallelograms = 0;
    
    for (int i = 0; i < k; ) {
        int j = i;
        int currentVectorCount = 0;
        
        while (j < k && segments[i].dx == segments[j].dx && segments[i].dy == segments[j].dy) {
            int l = j;
            while (l < k && segments[i].dx == segments[l].dx && 
                            segments[i].dy == segments[l].dy && 
                            segments[j].c == segments[l].c) {
                l++;
            }
            
            int countOnThisLine = l - j;
            parallelograms += currentVectorCount * countOnThisLine;
            currentVectorCount += countOnThisLine;
            j = l;
        }
        i = j;
    }

    free(segments);
    
    // Total = (1 * Trapezoids + 2 * Parallelograms) - (2 * Parallelograms) / 2
    //  i.e  = Trapezoids + Parallelograms
    return totalTrapezoids - (parallelograms / 2);
}