/**
 * Author: Daniel
 * Created Time: 2020-12-10 23:11:55
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
const int N = 1010, M = 1010, mod = 9901;

int n, m;
int f[N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) f[1][i] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            for (int k = 1; k <= i - 2; k ++ )
                (f[i][j] += f[k][j - 1] * f[i - 1 - k][j - 1] % mod) %= mod;
    cout << (f[n][m] - f[n][m - 1] + mod) % mod << '\n';
    return 0;
}

// GOOD LUCK!!!
