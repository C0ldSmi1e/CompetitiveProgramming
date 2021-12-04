/**
 * Author: Daniel
 * Created Time: 2021-05-29 20:45:44
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/arc121/tasks/arc121_b
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

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) 
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) 
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }

void debug_out() { cout << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }

#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;
const LL INF = 4e16;



// read the question carefully!!!
int main()
{
    SOS;

    int n;
    cin >> n;
    VE<VL> g(3);
    for (int i = 0; i < n * 2; i ++ )
    {
        LL a;
        char c;
        cin >> a >> c;
        if (c == 'R') g[0].EB(a);
        if (c == 'G') g[1].EB(a);
        if (c == 'B') g[2].EB(a);
    }
    VE<VL> b;
    VL d;
    for (auto &u : g)
    {
        sort(ALL(u));
        int tn = SZ(u);
        if (tn & 1) b.EB(u);
        else d = u;
    }
    LL res = 0;
    if (SZ(b))
    {
        assert(SZ(b) == 2);
        res = INF;
        int na = SZ(b[0]), nc = SZ(b[1]);
        for (int i = 0; i < na; i ++ )
        {
            int p = (int)(LB(ALL(b[1]), b[0][i]) - b[1].begin());
            if (p < nc) res = min(res, abs(b[0][i] - b[1][p]));
            p -- ;
            if (p >= 0) res = min(res, abs(b[0][i] - b[1][p]));
        }
        int nd = SZ(d);
        if (nd)
        {
            VE<PA<LL, int>> ans[2];
            ans[0].clear();
            ans[1].clear();
            for (int i = 0; i < nd; i ++ )
            {
                LL x = INF, y = INF;
                int p = (int)(LB(ALL(b[0]), d[i]) - b[0].begin());
                if (p < nd) x = abs(b[0][p] - d[i]);
                p -- ;
                if (p >= 0) y = abs(b[0][p] - d[i]);
                if (x < INF || y < INF) ans[0].EB(min(x, y), i);
                x = y = INF;
                p = (int)(LB(ALL(b[1]), d[i]) - b[1].begin());
                if (p < nd) x = abs(b[1][p] - d[i]);
                p -- ;
                if (p >= 0) y = abs(b[1][p] - d[i]);
                if (x < INF || y < INF) ans[1].EB(min(x, y), i);
            }
            sort(ALL(ans[0]));
            sort(ALL(ans[1]));
            if (ans[0][0].S != ans[1][0].S) res = min(res, ans[0][0].F + ans[1][0].F);
            if (ans[0][1].S != ans[1][0].S) res = min(res, ans[0][1].F + ans[1][0].F);
            if (ans[0][0].S != ans[1][1].S) res = min(res, ans[0][0].F + ans[1][1].F);
            if (ans[0][1].S != ans[1][1].S) res = min(res, ans[0][1].F + ans[1][1].F);
        }
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
