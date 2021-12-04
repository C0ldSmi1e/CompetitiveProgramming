#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 4e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    long long w;
    cin >> n >> m >> w;
    vector<vector<int>> g(n, vector<int>(m));
    vector<pair<int, int>> portal;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            cin >> g[i][j];
            if (g[i][j] > 0)
                portal.emplace_back(i, j);
        }
    auto bfs = [&](int sx, int sy, vector<vector<int>> &dist)
    {
        dist[sx][sy] = 0;
        vector<pair<int, int>> q;
        q.emplace_back(sx, sy);
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int qq = 0; qq < (int)q.size(); qq ++ )
        {
            auto [x, y] = q[qq];
            for (int i = 0; i < 4; i ++ )
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                if (g[tx][ty] == -1 || dist[tx][ty] != -1) continue;
                dist[tx][ty] = dist[x][y] + 1;
                q.emplace_back(tx, ty);
            }
        }
    };
    vector<vector<int>> dist1(n, vector<int>(m, -1));
    bfs(0, 0, dist1);
    vector<vector<int>> dist2(n, vector<int>(m, -1));
    bfs(n - 1, m - 1, dist2);
    long long res = INF;
    if (dist1[n - 1][m - 1] != -1) res = dist1[n - 1][m - 1] * w;
    long long mn1 = INF, mn2 = INF;
    for (auto &[x, y] : portal)
        if (dist1[x][y] != -1)
            mn1 = min(mn1, dist1[x][y] * w + g[x][y]);
    for (auto &[x, y] : portal)
        if (dist2[x][y] != -1)
            mn2 = min(mn2, dist2[x][y] * w + g[x][y]);
    res = min(res, mn1 + mn2);
    if (res == INF) res = -1;
    cout << res << '\n';
    return 0;
}
