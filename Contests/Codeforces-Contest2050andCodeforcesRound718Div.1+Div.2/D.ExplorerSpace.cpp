/**
 * Author: Daniel
 * Created Time: 2021-04-25 17:39:53
**/

// time-limit: 2000
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
const int N = 510, M = 25, INF = 0x3f3f3f3f;



// read the question carefully!!!
int main()
{
    SOS;

    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1)
    {
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                cout << -1 << " \n"[j == m - 1];
        return 0;
    }
    VE<VI> r(n, VI(m)), c(n, VI(m));
    for (int i = 0; i < n; i ++ )
        for (int j = 1; j < m; j ++ )
            cin >> r[i][j];
    for (int i = 1; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> c[i][j];
    VE<VE<VI>> f(n, VE<VI>(m, VI(k, INF)));
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            f[i][j][0] = 0;
    for (int cnt = 0; cnt < k / 2; cnt ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
            {
                if (i > 0) f[i - 1][j][cnt + 1] = min(f[i - 1][j][cnt + 1], f[i][j][cnt] + c[i][j]);
                if (j > 0) f[i][j - 1][cnt + 1] = min(f[i][j - 1][cnt + 1], f[i][j][cnt] + r[i][j]);
                if (i < n - 1) f[i + 1][j][cnt + 1] = min(f[i + 1][j][cnt + 1], f[i][j][cnt] + c[i + 1][j]);
                if (j < m - 1) f[i][j + 1][cnt + 1] = min(f[i][j + 1][cnt + 1], f[i][j][cnt] + r[i][j + 1]);
            }
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cout << f[i][j][k / 2] * 2 << " \n"[j == m - 1];
    return 0;
}

// GOOD LUCK!!!
