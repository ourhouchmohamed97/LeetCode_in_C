// Champagne Tower

#include <math.h>
#include <string.h>

double champagneTower(int poured, int query_row, int query_glass) {
    double flow[102][102] = {0.0};

    flow[0][0] = (double)poured;

    for (int r = 0; r <= query_row; ++r) {
        for (int c = 0; c <= r; ++c) {
            double q = (flow[r][c] - 1.0) / 2.0;

            if (q > 0) {
                flow[r + 1][c] += q;
                flow[r + 1][c + 1] += q;
            }
        }
    }

    return fmin(1.0, flow[query_row][query_glass]);
}