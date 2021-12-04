/**
 * Author: Daniel
 * Created Time: 2020-12-15 00:23:21
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

#define y1 _y_1
#define lson (u << 1)
#define rson (u << 1 | 1)

int n, m;
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
    int l, r, len, cnt;
} tr[N << 3];

VI ys;
int find(int x)
{
    return lower_bound(ALL(ys), x) - ys.begin();
}

void pushup(int u)
{
    if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else if (tr[u].l == tr[u].r) tr[u].len = 0;
    else tr[u].len = tr[lson].len + tr[rson].len;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
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

// read the question carefully!!!
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
    ys.ER(unique(ALL(ys)), ys.end());
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

// GOOD LUCK!!!
