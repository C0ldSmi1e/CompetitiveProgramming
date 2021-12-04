/**
 * Author: Daniel
 * Created Time: 2021-10-17 19:08:51
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1575/problem/J
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

    int n, m, k;
    cin >> n >> m >> k;
    VE<VI> g(n, VI(m));
    for (auto &u : g)
        for (auto &v : u)
            cin >> v;
    VE<VB> st(n, VB(m, false));
    for (int j = 0; j < m; j ++ )
        if (g[n - 1][j] == 2)
            st[n - 1][j] = true;
    for (int i = n - 2; i >= 0; i -- )
        for (int j = 0; j < m; j ++ )
            if (st[i + 1][j] == true && g[i][j] == 2)
                st[i][j] = true;
    while (k -- )
    {
        int c;
        cin >> c;
        c -- ;
        int x = 0, y = c;
        while (true)
        {
            assert(x >= 0 && x < n);
            assert(y >= 0 && y < m);
            if (st[x][y]) break;
            if (g[x][y] == 1)
            {
                g[x][y] = 2;
                if (x + 1 == n || (x + 1 < n && st[x + 1][y]))
                    st[x][y] = true;
                y ++ ;
            }
            else if (g[x][y] == 2)
            {
                x ++ ;
                if (x >= n)
                {
                    assert(st[x - 1][y] == true);
                    break;
                }
            }
            else if (g[x][y] == 3)
            {
                g[x][y] = 2;
                if (x + 1 == n || (x + 1 < n && st[x + 1][y]))
                    st[x][y] = true;
                y -- ;
            }
            else assert(false);
        }
        cout << y + 1 << ' ';
    }
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
