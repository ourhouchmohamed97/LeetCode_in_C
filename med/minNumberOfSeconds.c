// Minimum Number of Seconds to Make Mountain Height Zero

#include <math.h>
#include <stdio.h>

long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize) {
    int maxT = 0;
    for (int i = 0; i < workerTimesSize; i++) {
        if (workerTimes[i] > maxT) maxT = workerTimes[i];
    }

    long long l = 1;
    long long r = (long long)maxT * mountainHeight * (mountainHeight + 1) / 2;
    long long ans = r;

    while (l <= r) {
        long long m = l + (r - l) / 2;
        long long tmp = 0;

        for (int i = 0; i < workerTimesSize; i++) {
            long long t = workerTimes[i];
            long long lim = m / t;
            
            long long k = (long long)((-1.0 + sqrt(1.0 + 8.0 * lim)) / 2.0 + 1e-9);
            tmp += k;
            
            if (tmp >= mountainHeight) {
                break;
            }
        }

        if (tmp >= mountainHeight) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
}