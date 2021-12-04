/**
 * Author: Daniel
 * Created Time: 2021-03-13 11:12:36
**/

// time-limit: 2500
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
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef vector<pair<int, int> > VPII;

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

int n, m, res = 1;
int a[N];
map<int, int> mp[N];
multiset<int> S[N];

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


void add(int pos, int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt ++ ; 
                x /= i;
            }
            int now = mp[pos][i];
            mp[pos][i] += cnt;
            int mn = 0;
            if (SZ(S[i]) == n) mn = *S[i].begin();
            if (now) S[i].ER(S[i].find(now));
            S[i].IS(now + cnt);
            if (SZ(S[i]) == n) res = (LL)res * qp(i, *S[i].begin() - mn) % mod;
        }
    if (x > 1)
    {
        int now = mp[pos][x];
        mp[pos][x] += 1;
        int mn = 0;
        if (SZ(S[x]) == n) mn = *S[x].begin();
        if (now) S[x].ER(S[x].find(now));
        S[x].IS(now + 1);
        if (SZ(S[x]) == n) res = (LL)res * qp(x, *S[x].begin() - mn) % mod;
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        add(i, a[i]);
    }
    while (m -- )
    {
        int i, x;
        cin >> i >> x;
        add(i, x);
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
