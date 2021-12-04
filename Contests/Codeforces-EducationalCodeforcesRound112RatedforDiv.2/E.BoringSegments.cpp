/**
 * Author: Daniel
 * Created Time: 2021-09-22 00:29:33
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1555/problem/E
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
const int N = 1000010, M = 1010, INF = 0x3f3f3f3f;

struct Node
{
    int l, r;
    int val, mn;
    int add;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    tr[u].val = tr[lson].val + tr[rson].val;
    tr[u].mn = min(tr[lson].mn, tr[rson].mn);
}

void pushdown(int u)
{
    tr[lson].val += tr[u].add;
    tr[rson].val += tr[u].add;
    tr[lson].mn += tr[u].add;
    tr[rson].mn += tr[u].add;
    tr[lson].add += tr[u].add;
    tr[rson].add += tr[u].add;
    tr[u].add = 0;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0, 0};
    if (l == r) return;
    else
    {
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].val += add * (tr[u].r - tr[u].l + 1);
        tr[u].mn += add;
        tr[u].add += add;
    }
    else
    {
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(lson, l, r, add);
        if (r > mid) modify(rson, l, r, add);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mn;
    else
    {
        pushdown(u);
        int res = INF;
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) res = min(res, query(lson, l, r));
        if (r > mid) res = min(res, query(rson, l, r));
        return res;
    }
}

struct Seg
{
    int l, r, w;
    bool operator<(const Seg &t) const
    {
        return w < t.w;
    };
};

// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    m -- ;
    VE<Seg> seg(n);
    for (int i = 0; i < n; i ++ )
    {
        int l, r, w;
        cin >> l >> r >> w;
        r -- ;
        seg[i] = {l, r, w};
    }
    sort(ALL(seg));
    build(1, 1, m);
    int res = (int) (1e6 + 10);
    for (int i = 0, j = 0; i < n; i ++ )
    {
        while (j < n && query(1, 1, m) == 0)
        {
            modify(1, seg[j].l, seg[j].r, 1);
            j ++ ;
        }
        assert(j > i);
        if (query(1, 1, m) == 0) break;
        res = min(res, seg[j - 1].w - seg[i].w);
        modify(1, seg[i].l, seg[i].r, -1);
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
