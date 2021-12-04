/**
 * Author: Daniel
 * Created Time: 2020-12-27 17:58:56
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 40, M = 1000010, INF = 0x3f3f3f3f;

int n, m;
int dist_sum[N][N], dist_min[N][N], dist[N][N][2];
PII king;
bool st[N][N][2];
struct Node
{
    int x, y, z;
} q[M];


int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int sx, int sy)
{
    int hh = 0, tt = -1;
    memset(dist, 0x3f, sizeof dist);
    q[ ++ tt] = {sx, sy, 0};
    dist[sx][sy][0] = 0;

    while (hh <= tt)
    {
        auto t = q[hh ++ ];

        for (int i = 0; i < 8; i ++ )
        {
            int tx = t.x + dx[i];
            int ty = t.y + dy[i];

            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;

            if (dist[tx][ty][t.z] > dist[t.x][t.y][t.z] + 1)
            {
                dist[tx][ty][t.z] = dist[t.x][t.y][t.z] + 1;
                q[ ++ tt] = {tx, ty, t.z};
            }

            if (t.z == 0)
            {
                int d = max(abs(king.F - tx), abs(king.S - ty));

                if (dist[tx][ty][t.z] + d < dist[tx][ty][1])
                {
                    dist[tx][ty][1] = dist[tx][ty][t.z] + d;
                    q[ ++ tt] = {tx, ty, 1};
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (dist[i][j][0] == INF) dist_sum[i][j] = INF;
            else dist_sum[i][j] += dist[i][j][0];

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            dist_min[i][j] = min(dist_min[i][j], dist[i][j][1] - dist[i][j][0]);
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;

    int x;
    char y;
    cin >> y >> x;
    king = MP(x, y - 'A' + 1);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            dist_min[i][j] = max(abs(i - king.F), abs(j - king.S));

    while (cin >> y >> x) bfs(x, y - 'A' + 1);

    int res = INF;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            res = min(res, dist_sum[i][j] + dist_min[i][j]);
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
