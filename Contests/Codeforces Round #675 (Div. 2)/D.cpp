
// Problem: D. Returning Home
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
typedef pair<LL, int> PLI;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<PLI, vector<PLI>, greater<PLI> > RHEAP;

// check the limitation!!!
const int N = 200010, M = 2 * N;

int _, n;
int h[N], e[M], w[M], ne[M], idx;
int sx, sy, fx, fy;
LL dist[N];
pair<PII, int> edge_x[N], edge_y[N];
PII p[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void add_edge(pair<PII, int> edge[])
{
	sort(edge + 1, edge + n + 1);
	for (int i = 2; i <= n; i ++ )
	{
		int x1 = edge[i - 1].F.F, y1 = edge[i - 1].F.S, id1 = edge[i - 1].S;
		int x2 = edge[i].F.F, y2 = edge[i].F.S, id2 = edge[i].S;
		add(id1, id2, min(abs(x1 - x2), abs(y1 - y2)));
		add(id2, id1, min(abs(x1 - x2), abs(y1 - y2)));
	}
}

void Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0LL;
	RHEAP heap;
	heap.push(MP(dist[1], 1));
	
	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();
		
		LL d = t.F;
		int v = t.S;
		if (st[v]) continue;
		st[v] = true;
		
		for (int i = h[v]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > d + w[i])
			{
				dist[j] = d + w[i];
				heap.push(MP(dist[j], j));
			}
		}
	}
}

// read the question carefully!!!
int main()
{
	IOS
	
	memset(h, -1, sizeof h);
	
	cin >> _ >> n;
	cin >> sx >> sy >> fx >> fy;
	
	n ++ ;
	p[1] = MP(sx, sy);
	edge_x[1] = MP(MP(sx, sy), 1);
	edge_y[1] = MP(MP(sy, sx), 1);
	for (int i = 2; i <= n; i ++ )
	{
		int a, b;
		cin >> a >> b;
		p[i] = MP(a, b);
		edge_x[i] = MP(MP(a, b), i);
		edge_y[i] = MP(MP(b, a), i);
	}
	
	add_edge(edge_x);
	add_edge(edge_y);
	
	Dijkstra();
	
	LL res = 4e18;
	for (int i = 1; i <= n; i ++ ) res = min(res, dist[i] + abs(fx - p[i].F) + abs(fy - p[i].S));
	cout << res << '\n';
    return 0;
}