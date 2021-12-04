/**
 * Author: Daniel
 * Created Time: 2020-12-27 19:47:52
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
const int N = 1010, M = 1010;

int n, a[N];
int f[N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i ++ ) 
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int len = 1; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;

            if (l == r) f[l][r] = a[l];
            else f[l][r] = max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);
        }
    cout << (sum + f[1][n]) / 2 << ' ' << (sum - f[1][n]) / 2 << '\n';
    return 0;
}

// GOOD LUCK!!!
