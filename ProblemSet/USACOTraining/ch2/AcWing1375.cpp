/**
 * Author: Daniel
 * Created Time: 2020-12-11 13:15:24
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
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 1010, M = 1010, INF = 0x3f3f3f3f;

int n = 52;
int m;
int f[N][N];

int get(char c)
{
    if (c <= 'Z' && c >= 'A') return 1 + c - 'A';
    else return 27 + c - 'a';
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) f[i][j] = 0;
            else f[i][j] = INF;

    cin >> m;
    for (int i = 0; i < m; i ++ )
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        int x = get(a), y = get(b);
        f[x][y] = f[y][x] = min(f[x][y], c);
    }

    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    int res = INF;
    char ans;
    for (int i = 1; i <= 25; i ++ )
        if (res > f[26][i])
        {
            res = f[26][i];
            ans = 'A' + i - 1;
        }
    cout << ans << ' ' << res << '\n';
    return 0;
}

// GOOD LUCK!!!
