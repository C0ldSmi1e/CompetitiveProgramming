/**
 * Author: Daniel
 * Created Time: 2021-02-17 09:46:11
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
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
const int N = 1010, M = 1010, mod = 1e9 + 7;

int n;
int C[N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i <= n; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

    int res = 0;
    for (int i = 2; i <= n - 2; i ++ )
        res = (res + C[n - 1][i] * (LL)(i - 1) % mod * (n - i - 1) % mod) % mod;
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
