/**
 * Author: Daniel
 * Created Time: 2021-04-15 20:46:39
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
const int N = 200010, M = 1010;

int T;
int n, m;
int a[N];
int p[N];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i ++ ) p[i] = i;
        VPII b;
        for (int i = 1; i <= n; i ++ )
        {
            cin >> a[i];
            b.EB(a[i], i);
        }
        sort(ALL(b));
        LL res = 0;
        for (auto &[x, i] : b)
        {
            if (x >= m) break;
            int t = i;
            while (i < n)
            {
                if (a[i + 1] % x != 0) break;
                int pa = find(i), pb = find(i + 1);
                if (pa == pb) break;
                p[pb] = pa;
                res += x;
                i ++ ;
            }
            i = t;
            while (i > 1)
            {
                if (a[i - 1] % x != 0) break;
                int pa = find(i), pb = find(i - 1);
                if (pa == pb) break;
                p[pb] = pa;
                res += x;
                i -- ;
            }
        }
        for (int i = 1; i < n; i ++ )
        {
            int pa = find(i), pb = find(i + 1);
            if (pa != pb)
            {
                res += m;
                p[pa] = pb;
            }
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
