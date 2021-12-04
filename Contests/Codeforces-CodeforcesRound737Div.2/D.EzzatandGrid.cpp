/**
 * Author: Daniel
 * Created Time: 2021-09-24 21:03:25
**/

// time-limit: 2500
// problem-url: https://codeforces.com/contest/1557/problem/D
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
const int N = 300010, M = 1010;

struct Node
{
    int l, r;
    int mx, idx;
    int tag;
} tr[N << 3];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    if (tr[lson].mx > tr[u].mx)
    {
        tr[u].mx = tr[lson].mx;
        tr[u].idx = tr[lson].idx;
    }
    if (tr[rson].mx > tr[u].mx)
    {
        tr[u].mx = tr[rson].mx;
        tr[u].idx = tr[rson].idx;
    }
}

void pushdown(int u)
{
    if (tr[u].tag != -1)
    {
        tr[lson].mx = tr[u].tag;
        tr[lson].idx = tr[u].idx;
        tr[lson].tag = tr[u].tag;
        tr[rson].mx = tr[u].tag;
        tr[rson].idx = tr[u].idx;
        tr[rson].tag = tr[u].tag;
        tr[u].tag = -1;
    }
    //if (tr[u].tag1 > tr[lson].mx)
    //{
    //    tr[lson].mx = tr[u].tag1;
    //    tr[lson].idx = tr[u].tag2;
    //}
    //if (tr[u].tag1 > tr[rson].mx)
    //{
    //    tr[rson].mx = tr[u].tag1;
    //    tr[rson].idx = tr[u].tag2;
    //}
    //tr[u].tag1 = tr[u].tag2 = 0;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0, -1};
    if (l == r) tr[u].mx = tr[u].idx = 0;
    else
    {
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int mx, int idx)
{
    if (l <= tr[u].l && tr[u].r <= r)
    {
        tr[u].mx = tr[u].tag = mx;
        tr[u].idx =  idx;
    }
    else
    {
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(lson, l, r, mx, idx);
        if (r > mid) modify(rson, l, r, mx, idx);
        pushup(u);
    }
}

PII query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r) return {tr[u].mx, tr[u].idx};
    else
    {
        pushdown(u);
        PII res{0, 0};
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) res = max(res, query(lson, l, r));
        if (r > mid) res = max(res, query(rson, l, r));
        return res;
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    VE<VPII> row(n + 1);
    VI val;
    for (int i = 0; i < m; i ++ )
    {
        int x, l, r;
        cin >> x >> l >> r;
        val.EB(l);
        val.EB(r);
        row[x].EB(l, r);
    }
    sort(ALL(val));
    val.ER(unique(ALL(val)), val.end());
    int k = SZ(val);
    build(1, 1, k);
    VI pre(n + 1);
    int res = 0, last = -1;
    for (int i = 1; i <= n; i ++ )
        for (auto &[l, r] : row[i])
        {
            l = (int) (LB(ALL(val), l) - val.begin() + 1);
            r = (int) (LB(ALL(val), r) - val.begin() + 1);
        }
    for (int i = 1; i <= n; i ++ )
    {
        PII t{0, 0};
        for (auto &[l, r] : row[i])
        {
            t = max(t, query(1, l, r));
        }
        int cur = t.F + 1;
        pre[i] = t.S;
        if (cur > res)
        {
            res = cur;
            last = i;
        }
        for (auto &[l, r] : row[i])
            modify(1, l, r, cur, i);
    }
    VB st(n + 1);
    while (last > 0)
    {
        st[last] = true;
        last = pre[last];
    }
    VI ans;
    for (int i = 1; i <= n; i ++ )
        if (!st[i])
            ans.EB(i);
    assert(n - res == SZ(ans));
    cout << SZ(ans) << '\n';
    for (auto &u : ans) cout << u << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
