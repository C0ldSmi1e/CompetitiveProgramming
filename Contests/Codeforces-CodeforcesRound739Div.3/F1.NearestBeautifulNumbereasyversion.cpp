/**
 * Author: Daniel
 * Created Time: 2021-09-21 23:17:02
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1560/problem/F1
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;



// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    set<LL> S1, S2;
    auto get = [&](LL x) -> int
    {
        if (x == 0) return 1;
        set<LL> S;
        while (x > 0)
        {
            S.IS(x % 10);
            x /= 10;
        }
        return SZ(S);
    };
    function<void(int, int, int, LL)> dfs = [&](int u, int x, int y, LL val) -> void
    {
        if (get(val) == 1) S1.IS(val);
        else S2.IS(val);
        if (u >= 10) return;
        dfs(u + 1, x, y, val * 10 + x);
        dfs(u + 1, x, y, val * 10 + y);
    };
    for (int i = 0; i <= 9; i ++ )
        for (int j = i + 1; j <= 9; j ++ )
            dfs(0, i, j, 0);
    while (T -- )
    {
        LL n, k;
        cin >> n >> k;
        LL res = (*S1.LB(n));
        if (k == 2) res = min(res, (*S2.LB(n)));
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
