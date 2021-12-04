
// Problem : Lowest Common Ancestor
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TALCA
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB push_back
#define SZ(x) x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 200010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][20];
int q[M];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs()
{
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[1] = 1;
	int hh = 0, tt = -1;
	q[ ++ tt] = 1;
	
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (depth[j] > depth[t] + 1)
			{
				depth[j] = depth[t] + 1;
				q[ ++ tt] = j;
				fa[j][0] = t;
				for (int k = 1; k <= 19; k ++ )
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
			}
		}
	}
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 19; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = 19; k >= 0; k -- )
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int dist(int a, int b)
{
	int anc = lca(a, b);
	return depth[a] + depth[b] - 2 * depth[anc];
}

int main()
{
	IOS
	
	memset(h, -1, sizeof h);
	
	cin >> n;
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	bfs();
	
	PII p[6];
	cin >> m;
	while (m -- )
	{
		int r, u, v;
		cin >> r >> u >> v;
		
		p[0].S = r;
		p[1].S = u;
		p[2].S = v;
		p[3].S = lca(r, u);
		p[4].S = lca(r, v);
		p[5].S = lca(u, v);
		
		for (int i = 0; i < 6; i ++ )
		{
			int anc = p[i].S;
			p[i].F = dist(u, anc) + dist(r, anc) + dist(v, anc);
		}
		sort(p, p + 6);
		cout << p[0].S << '\n';
	}
    return 0;
}
