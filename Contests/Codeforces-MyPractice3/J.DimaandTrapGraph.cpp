#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 3010, INF = 0x3f3f3f3f;

int n, m;
int p[N];
struct Edge
{
    int a, b, l, r;
    bool operator<(const Edge &t) const
    {
        return r > t.r;
    }
} e[M];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        e[i] = {a, b, l, r};
    }
    sort(e, e + m);
    int res = 0;
    for (int i = 0; i < m; i ++ )
    {
        int L = e[i].l, R = INF;
        for (int i = 0; i <= n; i ++ ) p[i] = i;
        for (int j = 0; j < m; j ++ )
        {
            int l = e[j].l, r = e[j].r;
            if (l > L) continue;
            int pa = find(e[j].a), pb = find(e[j].b);
            R = min(R, r);
            p[pa] = pb;
            if (find(1) == find(n)) res = max(res, R - L + 1);
        }
    }
    if (res) cout << res << '\n';
    else cout << "Nice work, Dima!\n";
    return 0;
}
