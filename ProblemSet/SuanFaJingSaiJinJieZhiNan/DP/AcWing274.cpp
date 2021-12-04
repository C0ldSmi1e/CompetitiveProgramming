/**
* Author: Name
* Created Time: 2020-11-18 23:44:41
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
const int N = 210, M = 1010, INF = 0x3f3f3f3f;

int m, n;
int p[M];
int g[N][N];
int f[2][N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> m >> n;
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> g[i][j];

    for (int i = 1; i <= n; i ++ ) cin >> p[i];

    p[0] = 3;
    memset(f, 0x3f, sizeof f);
    f[0][1][2] = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 1; j <= m; j ++ )
            for (int k = 1; k <= m; k ++ )
                if (f[i & 1][j][k] == INF) continue;
                else
                {
                    int v = f[i & 1][j][k];
                    if (p[i + 1] != j && p[i + 1] != k) f[i + 1 & 1][j][k] = min(f[i + 1 & 1][j][k], v + g[p[i]][p[i + 1]]);
                    if (p[i + 1] != p[i] && p[i + 1] != k) f[i + 1 & 1][p[i]][k] = min(f[i + 1 & 1][p[i]][k], v + g[j][p[i + 1]]);
                    if (p[i + 1] != p[i] && p[i + 1] != j) f[i + 1 & 1][j][p[i]] = min(f[i + 1 & 1][j][p[i]], v + g[k][p[i + 1]]);
                    f[i & 1][j][k] = INF;
                }
    
    int res = INF;
    for (int j = 1; j <= m; j ++ )
        for (int k = 1; k <= m; k ++ )
            res = min(res, f[n & 1][j][k]);
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
