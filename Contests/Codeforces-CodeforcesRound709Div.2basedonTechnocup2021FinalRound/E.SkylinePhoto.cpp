/**
 * Author: Daniel
 * Created Time: 2021-03-24 21:34:22
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
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
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
const int N = 300010, M = 1010;
const LL INF = 4e18;

int n;
LL h[N], b[N];
LL f[N];
int stk[N], top;
struct Node
{
    int l, r;
    LL val, mx;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    tr[u].mx = max(tr[lson].mx, tr[rson].mx);
}

void pushdown(int u)
{
    //tr[lson].val = max(tr[lson].val, tr[u].tag);
    //tr[lson].tag = max(tr[lson].tag, tr[u].tag);
    //tr[rson].val = max(tr[rson].val, tr[u].tag);
    //tr[rson].tag = max(tr[rson].tag, tr[u].tag);
    //tr[u].tag = -INF;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, -INF, -INF};
    if (l != r)
    {
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, LL v)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        if (l == r) tr[u].val = v;
        tr[u].mx = v;
        //tr[u].tag = max(tr[u].tag, v);
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(lson, l, r, v);
        if (r > mid) modify(rson, l, r, v);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
    else
    {
        pushdown(u);
        LL res = -INF;
        int mid = tr[u].r + tr[u].l >> 1;
        if (l <= mid) res = query(lson, l, r);
        if (r > mid) res = max(res, query(rson, l, r));
        return res;
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i ++ )
    {
        while (top && h[stk[top]] >= h[i]) top -- ;
        int j = stk[top];
        if (i == 1) f[i] = b[i];
        else if (!j) f[i] = query(1, 1, i - 1) + b[i];
        else f[i] = query(1, j, i - 1) + b[i];
        if (j) f[i] = max(f[i], f[j]);
        else f[i] = max(f[i], b[i]);
        modify(1, i, i, f[i]);
        stk[ ++ top] = i;
    }
    cout << f[n] << '\n';
    return 0;
}

// GOOD LUCK!!!
