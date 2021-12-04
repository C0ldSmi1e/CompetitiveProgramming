/**
 * Author: Daniel
 * Created Time: 2020-12-27 23:10:27
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
const int N = 110, M = 1010;

int n, m, t;
int f[N][N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> t >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int v;
        cin >> v;
        for (int j = 1; j <= m; j ++ )
            for (int k = 0; k <= t; k ++ )
            {
                f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
                if (k >= v) 
                {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - v] + 1);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + 1);
                }
            }
    }
    cout << f[n][m][t] << '\n';
    return 0;
}

// GOOD LUCK!!!
