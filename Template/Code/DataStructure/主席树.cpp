// 求区间第 k 小
const int N = 100010, M = 10010;

int n, m;
int a[N];
int root[N], idx;
struct Node
{
    int l, r, cnt;
} tr[N * 4 + N * 17];

VI nums;
int find(int x)
{
    return lower_bound(ALL(nums), x) - nums.begin();
}

void pushup(int u)
{
    tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
}

int build(int l, int r)
{
    int p = ++ idx;
    if (l == r) return p;

    int mid = l + r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x)
{
    int q = ++ idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].cnt ++ ;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid) tr[q].l = insert(tr[q].l, l, mid, x);
    else tr[q].r = insert(tr[q].r, mid + 1, r, x);
    pushup(q);
    return q;
}

int query(int q, int p, int l, int r, int k)
{
    if (l == r) return r;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = l + r >> 1;
    if (cnt >= k) return query(tr[q].l, tr[p].l, l, mid, k);
    else return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
}

int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        nums.EB(a[i]);
    }

    sort(ALL(nums));
    nums.ER(unique(ALL(nums)), nums.end());

    root[0] = build(0, SZ(nums) - 1);
    for (int i = 1; i <= n; i ++ ) root[i] = insert(root[i - 1], 0, SZ(nums) - 1, find(a[i]));

    int l, r, k;
    while (m -- )
    {
        cin >> l >> r >> k;
        cout << nums[query(root[r], root[l - 1], 0, SZ(nums) - 1, k)] << '\n';
    }
    return 0;
}



// 二分求区间出现次数超过一半的数
const int N = 300010;

int n, q;
int a[N];
int root[N], idx;
struct Node
{
    int l, r;
    int cnt;
} tr[N << 5];

void pushup(int u)
{
    tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
}

int build(int l, int r)
{
    int p = ++ idx;
    if (l == r) return p;
    else
    {
        int mid = l + r >> 1;
        tr[p].l = build(l, mid);
        tr[p].r = build(mid + 1, r);
        return p;
    }
}

int insert(int p, int l, int r, int x)
{
    int q = ++ idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].cnt ++ ;
        return q;
    }
    else
    {
        int mid = l + r >> 1;
        if (x <= mid) tr[q].l = insert(tr[q].l, l, mid, x);
        else tr[q].r = insert(tr[q].r, mid + 1, r, x);
        pushup(q);
        return q;
    }
}

int query(int p, int q, int l, int r, int len)
{
    if (l == r) return tr[q].cnt - tr[p].cnt;
    int sum_l = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int sum_r = tr[tr[q].r].cnt - tr[tr[p].r].cnt;
    int mid = l + r >> 1;
    int limit = (len + 1) / 2;
    if (sum_l <= limit && sum_r <= limit) return 0;
    else if (sum_l > limit) return query(tr[p].l, tr[q].l, l, mid, len);
    else if (sum_r > limit) return query(tr[p].r, tr[q].r, mid + 1, r, len);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    root[0] = build(1, n);
    for (int i = 1; i <= n; i ++ ) root[i] = insert(root[i - 1], 1, n, a[i]);
    while (q -- )
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int cnt = query(root[l - 1], root[r], 1, n, len);
        if (cnt <= (len + 1) / 2) cout << "1\n";
        else cout << 2 * cnt - len << '\n';
    }
    return 0;
}
