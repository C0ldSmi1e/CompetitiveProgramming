#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010;
const LL INF = 4e18;

int n;
int h[N], b[N];
int stk[N], top;
LL f[N];
LL tr[N];

#define lowbit(x) (x & -x)

void build()
{
    for (int i = 1; i <= n; i ++ )
    {
        tr[i] = -INF;
        if (lowbit(i) <= n && lowbit(i) < N)
            tr[lowbit(i)] = max(tr[lowbit(i)], tr[i]);
    }
}

void update(int x, LL c)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] = c;
        int len = lowbit(i);
        for (int j = 1; j < len; j <<= 1)
            tr[i] = max(tr[i], tr[i - j]);
    }
}

LL query(int l, int r)
{
    LL res = -INF;
    while (true)
    {
        res = max(res, f[r]);
        if (l == r) break;
        for (r -- ; r - lowbit(r) >= l; r -= lowbit(r))
            res = max(res, tr[r]);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    build();
    f[1] = b[1];
    stk[ ++ top] = 1;
    update(1, f[1]);
    for (int i = 2; i <= n; i ++ )
    {
        while (top && h[stk[top]] >= h[i]) top -- ;
        if (!top) f[i] = b[i] + max(0LL, query(1, i - 1));
        else f[i] = max(f[stk[top]], query(stk[top], i - 1) + b[i]);
        update(i, f[i]);
        stk[ ++ top] = i;
    }
    cout << f[n] << '\n';
    return 0;
}
