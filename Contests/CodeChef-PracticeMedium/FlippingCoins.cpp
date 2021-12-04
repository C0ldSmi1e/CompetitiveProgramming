/**
*  Author: Daniel
*  Created Time: 2020-10-18 19:40:30
**/

// time-limit: 308.37
#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define SZ(x) (int)x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 100010, M = 1010;

int n, m;
struct Node
{
    int l, r, cnt;
} tr[N << 2];

void pushup(int u)
{
    tr[u].cnt = tr[1 << u].cnt + tr[1 << u | 1].cnt;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r) tr[u].cnt = 0;
    else
    {
        int mid = l + r >> 1;
        build(1 << u, l, mid);
        build(1 << u | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r)
{
    if (l == r) tr[u].cnt ^= 1;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(1 << u, l, mid);
        if (r > mid) modify(1 << u | 1, mid + 1, r);
        tr[u].cnt = r - l + 1 - tr[u].cnt;
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].cnt;
    else
    {
        int res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) res += query(1 << u, l, r);
        if (r > mid) res += query(1 << u | 1, l, r);
        return res;
    }
}

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> m;

    build(1, 1, n);

    while (m -- )
    {
        int t, l, r;
        cin >> t >> l >> r;
        l ++ , r ++ ;
        
        if (t) cout << query(1, l, r) << '\n';
        else modify(1, l, r);
    }
    return 0;
}
