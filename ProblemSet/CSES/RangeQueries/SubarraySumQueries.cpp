/**
 * Author: Daniel
 * Created Time: 2021-10-15 11:09:09
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 1010, INF = 0x3f3f3f3f;

int n, m;
int a[N];

struct Node
{
    int l, r;
    LL mx, lmx, rmx, sum;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    tr[u].mx = MAX(tr[lson].mx, tr[rson].mx, tr[lson].rmx + tr[rson].lmx);
    tr[u].lmx = max(tr[lson].lmx, tr[rson].lmx + tr[lson].sum);
    tr[u].rmx = max(tr[rson].rmx, tr[lson].rmx + tr[rson].sum);
    tr[u].sum = tr[lson].sum + tr[rson].sum;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0, 0, 0};
    if (l == r) tr[u].mx = tr[u].lmx = tr[u].rmx = tr[u].sum = a[r];
    else
    {
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, LL x)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].mx = tr[u].lmx = tr[u].rmx = tr[u].sum = x;
    }
    else
    {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(lson, l, r, x);
        if (r > mid) modify(rson, l, r, x);
        pushup(u);
    }
}

LL query()
{
    return tr[1].mx;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    build(1, 1, n);
    while (m -- )
    {
        int k, x;
        cin >> k >> x;
        modify(1, k, k, x);
        a[k] = x;
        cout << max(0LL, query()) << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
