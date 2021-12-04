/**
 * Author: Daniel
 * Created Time: 2021-05-08 20:19:44
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc200/tasks/abc200_d
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

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 210, M = 1010;

int n;
int a[N];
int f[N][N];
PII pre[N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] %= 200;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int k = 0; k < 200; k ++ )
            for (int ii = 0; ii < i; ii ++ )
            {
                int j = (a[i] + k) % 200;
                if (f[ii][k])
                {
                    f[i][j] = 1;
                    pre[i][j] = MP(ii, k);
                }
            }
    for (int k = 0; k < 200; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int ii = i + 1; ii <= n; ii ++ )
                if (f[i][k] && f[ii][k])
                {
                    cout << "YES\n";
                    VI res, ans;
                    int x = i, y = k;
                    while (x)
                    {
                        res.EB(x);
                        auto t = pre[x][y];
                        x = t.F, y = t.S;
                    }
                    x = ii, y = k;
                    while (x)
                    {
                        ans.EB(x);
                        auto t = pre[x][y];
                        x = t.F, y = t.S;
                    }
                    reverse(ALL(res));
                    reverse(ALL(ans));
                    assert(res != ans);
                    cout << SZ(res);
                    for (auto &u : res) cout << ' ' << u;
                    cout << '\n';
                    cout << SZ(ans);
                    for (auto &u : ans) cout << ' ' << u;
                    cout << '\n';
                    return 0;
                }
    cout << "NO\n";
    return 0;
}

// GOOD LUCK!!!
