// 普通线段树
const int N = 100010, M = 1010;

int n, m, mod;
LL a[N];
struct Node
{
    int l, r;
    LL v, mul, add;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    tr[u].v = (tr[lson].v + tr[rson].v) % mod;
}

void pushdown(int u)
{
    tr[lson].v = (tr[lson].v * tr[u].mul + (tr[lson].r - tr[lson].l + 1) * tr[u].add) % mod;
    tr[rson].v = (tr[rson].v * tr[u].mul + (tr[rson].r - tr[rson].l + 1) * tr[u].add) % mod;
    tr[lson].mul = tr[lson].mul * tr[u].mul % mod;
    tr[rson].mul = tr[rson].mul * tr[u].mul % mod;
    tr[lson].add = (tr[lson].add * tr[u].mul + tr[u].add) % mod;
    tr[rson].add = (tr[rson].add * tr[u].mul + tr[u].add) % mod;
    tr[u].mul = 1, tr[u].add = 0;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 1, 0};
    if (l == r) tr[u].v = a[r];
    else
    {
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, LL mul, LL add)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].v = (tr[u].v * mul + (tr[u].r - tr[u].l + 1) * add) % mod;
        tr[u].mul = tr[u].mul * mul % mod;
        tr[u].add = (tr[u].add * mul + add) % mod;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(lson, l, r, mul, add);
        if (r > mid) modify(rson, l, r, mul, add);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    else
    {
        pushdown(u);

        LL res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) res = (res + query(lson, l, r)) % mod;
        if (r > mid) res = (res + query(rson, l, r)) % mod;
        return res;
    }
}

int main()
{
    SOS;

    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    build(1, 1, n);

    while (m -- )
    {
        int op, l, r;
        LL k;
        cin >> op >> l >> r;

        if (op == 1)
        {
            cin >> k;
            modify(1, l, r, k, 0);
        }
        else if (op == 2)
        {
            cin >> k;
            modify(1, l, r, 1, k);
        }
        else cout << query(1, l, r) << '\n';
    }
    return 0;
}



// 扫描线
const int N = 100010, M = 1010;

int n, m;
VE<int> ys;
struct Seg
{
    int x, y1, y2, k;
    bool operator<(const Seg &t) const
    {
        return x < t.x;
    }
} seg[N << 1];
struct Node
{
    int l, r, cnt, len;
} tr[N << 3];

int find(int y)
{
    return lower_bound(ALL(ys), y) - ys.begin();
}

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u)
{
    if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else if (tr[u].l == tr[u].r) tr[u].len = 0;
    else tr[u].len = tr[lson].len + tr[rson].len;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0};
    if (l != r)
    {
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += k;
        pushup(u);
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(lson, l, r, k);
        if (r > mid) modify(rson, l, r, k);
        pushup(u);
    }
}

int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        seg[m ++ ] = {x1, y1, y2, 1};
        seg[m ++ ] = {x2, y1, y2, -1};
        ys.EB(y1);
        ys.EB(y2);
    }

    sort(ALL(ys));
    ys.erase(unique(ALL(ys)), ys.end());
    build(1, 0, SZ(ys) - 2);

    sort(seg, seg + m);

    LL res = 0;
    for (int i = 0; i < m; i ++ )
    {
        if (i) res += (LL)tr[1].len * (seg[i].x - seg[i - 1].x);
        modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
    }
    cout << res << '\n';
    return 0;
}
