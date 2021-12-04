/**
* Author: Name
* Created Time: 2020-11-18 13:06:07
**/

// time-limit: 1000
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
const int N = 110, M = 1010;

int T;
int n, m;
int g[N][N];
char s[N];
VE<PII> res;

void op(int x1, int y1, int x2, int y2, int x3, int y3)
{
    g[x1][y1] ^= 1;
    g[x2][y2] ^= 1;
    g[x3][y3] ^= 1;
    res.EB(MP(x1, y1));
    res.EB(MP(x2, y2));
    res.EB(MP(x3, y3));
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        res.clear();

        cin >> n >> m;
        for (int i = 1; i <= n; i ++ )
        {
            cin >> s + 1;
            for (int j = 1; j <= m; j ++ )
                g[i][j] = s[j] - '0';
        }

        for (int i = 1; i <= n - 2; i ++ )
            for (int j = 1; j <= m; j += 2)
                if (j + 1 <= m)
                {
                    if (g[i][j] == 0 && g[i][j + 1] == 0) continue;
                    else if (g[i][j] == 1 && g[i][j + 1] == 1) op(i, j, i, j + 1, i + 1, j);
                    else if (g[i][j] == 1 && g[i][j + 1] == 0) op(i, j, i + 1, j, i + 1, j + 1);
                    else if (g[i][j] == 0 && g[i][j + 1] == 1) op(i, j + 1, i + 1, j, i + 1, j + 1);
                }
                else
                {
                    if (g[i][j] == 0) continue;
                    else op(i, j, i + 1, j, i + 1, j - 1);
                }


        for (int j = 1; j <= m - 1; j ++ )
            if (g[n - 1][j] == 0 && g[n][j] == 0) continue;
            else if (g[n - 1][j] == 1 && g[n][j] == 1) op(n - 1, j, n, j, n, j + 1);
            else if (g[n - 1][j] == 1 && g[n][j] == 0) op(n - 1, j, n - 1, j + 1, n, j + 1);
            else if (g[n - 1][j] == 0 && g[n][j] == 1) op(n, j, n - 1, j + 1, n, j + 1);

        if (g[n - 1][m] == 1 && g[n][m] == 1)
        {
            op(n, m - 1, n - 1, m - 1, n, m);
            op(n - 1, m, n - 1, m - 1, n, m - 1);
        }
        else if (g[n - 1][m] == 1 && g[n][m] == 0)
        {
            op(n - 1, m, n, m - 1, n, m);
            op(n - 1, m, n - 1, m - 1, n, m);
            op(n - 1, m - 1, n, m - 1, n - 1, m);
        }
        else if (g[n - 1][m] == 0 && g[n][m] == 1)
        {
            op(n - 1, m - 1, n - 1, m, n, m);
            op(n - 1, m, n, m, n, m - 1);
            op(n - 1, m - 1, n, m - 1, n, m);
        }

        cout << SZ(res) / 3 << '\n';
        for (int i = 0; i < SZ(res); i += 3)
        {
            cout << res[i].F << ' ' << res[i].S << ' ';
            cout << res[i + 1].F << ' ' << res[i + 1].S << ' ';
            cout << res[i + 2].F << ' ' << res[i + 2].S << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
