/**
*  Author: Daniel
*  Created Time: 2020-11-06 09:49:05
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define V(x) vector<x>
#define EB emplace_back
#define PII P(int, int)
#define lowbit(x) (x & -x)
#define P(x, y) pair<x, y>
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define HEAP(x) priority_queue<x>
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define RHEAP(x) priority_queue<x, vector<x>, greater<x> >
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) { return '"' + s + '"'; }
 
string to_string(const char* s) { return to_string((string) s); } 
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

// check the limitation!!!
const int N = 100010, M = 1010;

int n, m;
int a[N];
struct Node
{
    int l, r;
    LL v, lazy;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    tr[u].v = tr[lson].v + tr[rson].v;
}

void pushdown(int u)
{
    if (tr[u].lazy)
    {
        tr[lson].v += tr[u].lazy * (tr[lson].r - tr[lson].l + 1);
        tr[rson].v += tr[u].lazy * (tr[rson].r - tr[rson].l + 1);
        tr[lson].lazy += tr[u].lazy;
        tr[rson].lazy += tr[u].lazy;
        tr[u].lazy = 0;
    }
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r) tr[u].v = a[r];
    else
    {
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, LL k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].v += (tr[u].r - tr[u].l + 1) * k;
        tr[u].lazy += k;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].r + tr[u].l >> 1;
        if (l <= mid) modify(lson, l, r, k);
        if (r > mid) modify(rson, l, r, k);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;

        LL res = 0;
        if (l <= mid) res += query(lson, l, r);
        if (r > mid) res += query(rson, l, r);
        return res;
    }
}

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    build(1, 1, n);

    while (m -- )
    {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
        {
            LL k;
            cin >> k;
            modify(1, l, r, k);
        }
        else cout << query(1, l, r) << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
