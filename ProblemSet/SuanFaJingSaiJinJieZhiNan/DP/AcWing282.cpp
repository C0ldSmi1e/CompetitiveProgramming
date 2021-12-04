/**
* Author: Daniel
* Created Time: 2020-11-27 23:02:09
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
const int N = 310, M = 1010;

int n;
int a[N];
int f[N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    memset(f, 0x3f, sizeof f);
    for (int len = 1; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;
            if (l == r) f[l][r] = 0;
            else
            {
                int sum = 0;
                for (int i = l; i <= r; i ++ ) sum += a[i];
                for (int i = l; i < r; i ++ )
                    f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r] + sum);
            }
        }
    cout << f[1][n] << '\n';
    return 0;
}

// GOOD LUCK!!!
