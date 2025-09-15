#include <bits/stdc++.h>
#include <ios>
using namespace std;

/*
BFS on state (r, c, dir)
dirs: 1=East, 2=West, 3=South, 4=North
moves:
    Turn left/right: cost 1
    Go k (k in 1..3): step k forward if all intermediate cells are 0
*/

struct State {
    int r, c, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N; // rows, cols
    if (!(cin >> M >> N)) return 0;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];
        
    auto toZeroIdx = [](int x){ return x - 1; };

    int sr, sc, sd, tr, tc, td;
    cin >> sr >> sc >> sd;
    cin >> tr >> tc >> td;

    sr = toZeroIdx(sr); sc = toZeroIdx(sc);
    tr = toZeroIdx(tr); tc = toZeroIdx(tc);

    int dr[5] = {0, 0, 0, 1, -1};
    int dc[5] = {0, 1, -1, 0, 0};

    auto inBounds = [&](int r, int c){
        return (0 <= r && r < M && 0 <= c && c < N);
    };

    const int INF = 1e9;
    vector<vector<array<int,5>>> dist(M, vector<array<int,5>>(N, {INF,INF,INF,INF,INF}));

    queue<State> q;
    dist[sr][sc][sd] = 0;
    q.push({sr, sc, sd});

    auto turnLeft = [&](int d)->int {
        // 왼쪽 회전 규칙
        if (d==1) return 4;
        if (d==2) return 3;
        if (d==3) return 1;
        return 2;
    };

    auto turnRight = [&](int d)->int {
        // 오른쪽 회전 규칙
        if (d==1) return 3;
        if (d==2) return 4;
        if (d==3) return 2;
        return 1;
    };

    while (!q.empty()) {
        auto [r, c, d] = q.front(); q.pop();
        int cur = dist[r][c][d];

        // Turn left
        {
            int nd = turnLeft(d);
            if (dist[r][c][nd] > cur + 1) {
                dist[r][c][nd] = cur + 1;
                q.push({r, c, nd});
            }
        }
        // Turn right
        {
            int nd = turnRight(d);
            if (dist[r][c][nd] > cur + 1) {
                dist[r][c][nd] = cur + 1;
                q.push({r, c, nd});
            }
        }

        // Go k (k in 1..3)
        for (int k = 1; k <= 3; ++k) {
            int nr = r + dr[d] * k;
            int nc = c + dc[d] * k;
            
            // Check intermediate cells
            // then, k=1,2,3 각각에 대해 한 칸씩 확인
            bool ok = true;
            for (int t = 1; t <= k; ++t) {
                int trr = r + dr[d] * t;
                int tcc = c + dc[d] * t;
                if (!inBounds(trr, tcc) || grid[trr][tcc] == 1) {
                    ok = false; break;
                }
            }


            if (dist[nr][nc][d] > cur + 1) {
                dist[nr][nc][d] = cur + 1;
                q.push({nr, nc, d});
            }
        }
    }

    int ans = dist[tr][tc][td];
    if (ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}