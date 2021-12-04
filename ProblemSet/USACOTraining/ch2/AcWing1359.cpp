/**
 * Author: Daniel
 * Created Time: 2020-12-02 14:45:48
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
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
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 110, M = 1000010;

int n, m;
int g[N][N];
int c[N][N];
PII q[M];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int bfs(int x, int y, int color)
{
    int area = 1;
    c[x][y] = color;
    int hh = 0, tt = -1;
    q[ ++ tt] = MP(x, y);
    
    while (hh <= tt)
    {
        auto t = q[hh ++ ];

        for (int i = 0; i < 4; i ++ )
        {
            int tx = t.F + dx[i];
            int ty = t.S + dy[i];

            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (c[tx][ty] || ((g[t.F][t.S] >> i) & 1)) continue;

            area ++ ;
            c[tx][ty] = color;
            q[ ++ tt] = MP(tx, ty);
        }
    }
    return area;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> g[i][j];

    int color = 0;
    map<int, int> area;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (!c[i][j])
            {
                color ++ ;
                area[color] = bfs(i, j, color);
            }

    cout << color << '\n';
    int maxa = 0;
    for (auto &u : area) maxa = max(maxa, u.S);
    cout << maxa << '\n';
    return 0;
}

// GOOD LUCK!!!
