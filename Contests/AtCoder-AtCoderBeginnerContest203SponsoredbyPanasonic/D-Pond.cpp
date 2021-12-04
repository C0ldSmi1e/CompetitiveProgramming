/**
 * Author: Daniel
 * Created Time: 2021-05-30 20:56:16
**/

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

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 1010, M = 1010;

int n, k, m;
int a[N][N];
int s[N][N];

bool check(int x)
{
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            s[i][j] = ((x >= a[i][j]) ? 1 : 0);
    //cout << "x: " << x << '\n';
    //for (int i = 1; i <= n; i ++ )
    //    for (int j = 1; j <= n; j ++ )
    //        cout << s[i][j] << " \n"[j == n];
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    //cout << "x: " << x << '\n';
    //for (int i = 1; i <= n; i ++ )
    //    for (int j = 1; j <= n; j ++ )
    //        cout << s[i][j] << " \n"[j == n];
    for (int i = k; i <= n; i ++ )
        for (int j = k; j <= n; j ++ )
            if (s[i][j] - s[i][j - k] - s[i - k][j] + s[i - k][j - k] >= m)
                return true;
    //cout << x << ":" << "false\n";
    return false;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];
    m = (k * k + 1) / 2;
    int l = 0, r = (int)1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}

// GOOD LUCK!!!
