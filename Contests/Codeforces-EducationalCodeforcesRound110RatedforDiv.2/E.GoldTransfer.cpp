/**
 * Author: Daniel
 * Created Time: 2021-06-06 15:02:26
**/

// time-limit: 4500
// problem-url: https://codeforces.com/contest/1535/problem/E
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
const int N = 100010, M = 20;



// read the question carefully!!!
int main()
{
    SOS;

    int n;
    cin >> n;
    VE<VI> g(n + 1);
    VL a(n + 1), c(n + 1);
    cin >> a[0] >> c[0];
    VE<VI> f(n + 1, VI(M));
    for (int i = 1; i <= n; i ++ )
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int fa;
            cin >> fa >> a[i] >> c[i];
            f[i][0] = fa;
            for (int j = 1; j < M; j ++ )
                f[i][j] = f[f[i][j - 1]][j - 1];
        }
        else
        {
            LL v, w;
            cin >> v >> w;
            LL cnt = 0, cost = 0;
            while (w > 0 && a[v] > 0)
            {
                int now = v;
                for (int j = M - 1; j >= 0; j -- )
                    if (a[f[now][j]] > 0)
                        now = f[now][j];
                LL take = min(w, a[now]);
                a[now] -= take;
                w -= take;
                cnt += take;
                cost += take * c[now];
            }
            cout << cnt << ' ' << cost << endl;
        }
    }
    return 0;
}

// GOOD LUCK!!!
