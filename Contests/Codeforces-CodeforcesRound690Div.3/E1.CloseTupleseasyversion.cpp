/**
 * Author: Daniel
 * Created Time: 2020-12-16 00:45:10
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
const int N = 200010, M = 1010, mod = 1e9 + 7;

int T;
int n, m, k;
int a[N];
int fact[N], infact[N];

int qp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
    }
}

int C(int a, int b)
{
    if (a < b) return 0;
	int res = (LL)fact[a] * infact[a - b] % mod * infact[b] % mod;
	return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    init();

    cin >> T;
    while (T -- )
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        sort(a, a + n);

        int res = 0;
        for (int i = 0; i < n; i ++ )
        {
            int r = upper_bound(a, a + n, a[i] + k) - a;
            int cnt = r - i;
            (res += C(cnt - 1, m - 1)) %= mod;
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
