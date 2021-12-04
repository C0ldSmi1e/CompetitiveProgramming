/**
 * Author: Daniel
 * Created Time: 2021-07-14 13:44:09
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
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) { return '"' + s + '"'; }
 
string to_string(const char* s) { return to_string((string)s); } 
 
string to_string(const char c) { return to_string((string)"" + c); } 
 
string to_string(bool b) { return (b ? "true" : "false"); }
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
        res += ", ";
    } 
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A>
string to_string(priority_queue<A> heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}
 
template <typename A>
string to_string(priority_queue<A, vector<A>, greater<A> > heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
 
template <typename ... Ts>
string to_string(const Ts& ... ts) {
    stringstream ss;
    const char* sep = "";
    ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
    return ss.str();
}
 
template <typename... Args>
string to_string(const std::tuple<Args...> &t) {
    string res = "(";
    apply([&](const auto&... ts) { res += to_string(ts...); }, t);
    res += ")";
    return res;
}
 
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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;
 
 

// read the question carefully!!!
int main()
{
    SOS;
 
    int n, k;
    cin >> n >> k;
    VE<VI> g(n);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        a -- , b -- ;
        g[a].EB(b);
        g[b].EB(a);
    }
    int mx_depth = 0;
    LL res = 0;
    VI sz(n), cnt(n);
    VB alive(n, true);
    function<int(int, int, int)> getCen = [&](int u, int fa, int tot)
    {
        for (auto &v : g[u])
            if (v != fa && alive[v] && sz[v] > tot / 2)
                return getCen(v, u, tot);
        return u;
    };
    function<void(int, int, int, int)> calc = [&](int u, int fa, int flag, int depth)
    {
        if (depth > k) return;
        if (flag) cnt[depth] ++ ;
        else res += cnt[k - depth];
        mx_depth = max(mx_depth, depth);
        for (auto &v : g[u])
            if (v != fa && alive[v])
                calc(v, u, flag, depth + 1);
    };
    function<int(int, int)> getCnt = [&](int u, int fa) -> int
    {
        sz[u] = 1;
        for (auto &v : g[u])
            if (v != fa && alive[v])
                sz[u] += getCnt(v, u);
        return sz[u];
    };
    function<void(int)> solve = [&](int u)
    {
        int tot = getCnt(u, -1);
        int centroid = getCen(u, -1, tot);
        alive[centroid] = false;
        debug(centroid);
        mx_depth = 0;
        cnt[0] = 1;
        for (auto &v : g[centroid])
            if (alive[v])
            {
                calc(v, centroid, 0, 1);
                calc(v, centroid, 1, 1);
            }
        for (int i = 1; i <= mx_depth; i ++ ) cnt[i] = 0;
        for (auto &v : g[centroid])
            if (alive[v])
                solve(v);
    };
    solve(0);
    cout << res << '\n';
    return 0;
}
 
// GOOD LUCK!!!
