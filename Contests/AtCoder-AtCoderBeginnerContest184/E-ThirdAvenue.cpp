/**
* Author: Name
* Created Time: 2020-11-22 21:31:01
**/

// time-limit: 3000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) (int)(x.size())
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
const int N = 2010, M = N * N;

int n, m;
int dist[N][N];
PII q[M];
char g[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
VE<PII> p[26];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;

    PII st, ed;
    for (int i = 1; i <= n; i ++ ) 
    {
        cin >> g[i] + 1;
        for (int j = 1; j <= m; j ++ )
            if (g[i][j] <= 'z' && g[i][j] >= 'a') p[g[i][j] - 'a'].EB(MP(i, j));
            else if (g[i][j] == 'S') st = MP(i, j);
            else if (g[i][j] == 'E') ed = MP(i, j);
    }



    memset(dist, -1, sizeof dist);
    int hh = 0, tt = -1; 
    q[ ++ tt] = st;
    dist[st.F][st.S] = 0;

    while (hh <= tt)
    {
        auto t = q[hh ++ ];

        if (g[t.F][t.S] == 'G')
        {
            cout << dist[t.F][t.S] << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i ++ )
        {
            int tx = t.F + dx[i];
            int ty = t.S + dy[i];

            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (dist[tx][ty] != -1 || g[tx][ty] == '#') continue;


            dist[tx][ty] = dist[t.F][t.S] + 1;
            q[ ++ tt] = MP(tx, ty);
            if (g[tx][ty] == 'G')
            {
                cout << dist[tx][ty] << '\n';
                return 0;
            }
        }

        if (g[t.F][t.S] <= 'z' && g[t.F][t.S] >= 'a')
        {
            for (auto &u : p[g[t.F][t.S] - 'a'])
            {
                int x = u.F, y = u.S;
                if (dist[x][y] != -1) continue;
                q[ ++ tt] = MP(x, y);
                dist[x][y] = dist[t.F][t.S] + 1;
                if (g[x][y] == 'G')
                {
                    cout << dist[x][y] << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}

// GOOD LUCK!!!
