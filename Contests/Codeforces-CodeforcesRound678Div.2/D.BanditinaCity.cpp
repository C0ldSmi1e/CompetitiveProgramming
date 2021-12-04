/**
*  Author: Daniel
*  Created Time: 2020-10-29 18:35:56
**/

// time-limit: 1000
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
const int N = 200010, M = 2 * N;

int n;
int h[N], e[M], ne[M], idx;
int leaves[N];
LL a[N];
LL f[N];

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fa)
{
    bool leaf = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;

        leaf = false;
        dfs(j, u);
        a[u] += a[j];
        leaves[u] += leaves[j];
        f[u] = max(f[u], f[j]);
    }

    if (leaf) leaves[u] = 1;
    f[u] = max(f[u], (LL)(a[u] + leaves[u] - 1) / leaves[u]);
}

// read the question carefully!!!
int main()
{
    IOS

    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 2; i <= n; i ++ )
    {
        int p;
        cin >> p;
        add_edge(i, p);
        add_edge(p, i);
    }

    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    dfs(1, -1);

    cout << f[1] << '\n';
    return 0;
}
