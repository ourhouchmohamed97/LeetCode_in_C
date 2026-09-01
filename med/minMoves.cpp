// Minimum Moves to Clean the Classroom

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        const int m = classroom.size();
        const int n = classroom[0].size();

        int sr = -1, sc = -1, cnt = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = classroom[i][j];
                if (ch == 'S')      { sr = i; sc = j; }
                else if (ch == 'L') { id[i][j] = cnt++; }
            }
        }

        if (cnt == 0) return 0;

        const int fullMask  = (1 << cnt) - 1;
        const int numMasks  =  1 << cnt;

        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(numMasks, -1)));

        struct State { int r, c, mask, en; };
        queue<State> q;
        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        static const int dr[] = {-1, 1, 0, 0};
        static const int dc[] = { 0, 0,-1, 1};

        int dist = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto [r, c, mask, en] = q.front(); q.pop();

                if (en < best[r][c][mask]) continue;
                if (mask == fullMask)      return dist;
                if (en == 0)               continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                    char ch = classroom[nr][nc];
                    if (ch == 'X') continue;

                    int newEn   = en - 1;
                    int newMask = mask;
                    if      (ch == 'L') newMask |= (1 << id[nr][nc]);
                    else if (ch == 'R') newEn = energy;

                    if (best[nr][nc][newMask] >= newEn) continue;
                    best[nr][nc][newMask] = newEn;
                    if (newMask == fullMask) return dist + 1;
                    q.push({nr, nc, newMask, newEn});
                }
            }
            dist++;
        }
        return -1;
    }
};