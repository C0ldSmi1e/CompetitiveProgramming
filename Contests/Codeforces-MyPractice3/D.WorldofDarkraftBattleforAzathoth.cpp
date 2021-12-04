#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010;
const LL INF = 4e18;

int n, m, p;
LL a[N], b[N];
struct Mon
{
    LL x, y, z;
    bool operator<(const Mon &t) const
    {
        return x < t.x;
    }
} mon[N];
struct Node
{
    int l, r;
    LL val, mx, lazy;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    tr[u].val = tr[lson].val + tr[rson].val;
    tr[u].mx = max(tr[lson].mx, tr[rson].mx);
}

void pushdown(int u)
{
    tr[lson].val += (tr[lson].r - tr[lson].l + 1) * tr[u].lazy;
    tr[rson].val += (tr[rson].r - tr[rson].l + 1) * tr[u].lazy;
    tr[lson].mx += tr[u].lazy;
    tr[rson].mx += tr[u].lazy;
    tr[lson].lazy += tr[u].lazy;
    tr[rson].lazy += tr[u].lazy;
    tr[u].lazy = 0;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r) tr[u].val = tr[u].mx = b[r], tr[u].lazy = 0;
    else
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
        tr[u].val += (tr[u].r - tr[u].l + 1) * v;
        tr[u].mx += v;
        tr[u].lazy += v;
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
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) res = max(res, query(lson, l, r));
        if (r > mid) res = max(res, query(rson, l, r));
        return res;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 0; i < N; i ++ ) a[i] = INF, b[i] = -INF;
    for (int i = 1; i <= n; i ++ )
    {
        LL x, y;
        cin >> x >> y;
        a[x] = min(a[x], y);
    }
    for (int i = 1; i <= m; i ++ )
    {
        LL x, y;
        cin >> x >> y;
        b[x] = max(b[x], -y);
    }
    for (int i = 1; i <= p; i ++ )
    {
        LL x, y, z;
        cin >> x >> y >> z;
        mon[i] = {x, y, z};
    }
    sort(mon + 1, mon + p + 1);
    build(1, 1, N - 1);
    LL res = -INF;
    for (int i = 1, j = 1; i < N; i ++ )
    {
        while (j <= p && mon[j].x < i)
        {
            modify(1, mon[j].y + 1, N - 1, mon[j].z);
            j ++ ;
        }
        res = max(res, query(1, 1, N - 1) - a[i]);
    }
    cout << res << '\n';
    return 0;
}
