/**
*  Author: Daniel
*  Created Time: 2020-10-24 16:43:51
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
typedef priority_queue<PII, vector<PII>, greater<PII> > RHEAP;

// check the limitation!!!
const int N = 1010, M = 2010;

int n, m, k;
int h[N], e[M], w[M], ne[M], idx;
int dist[N][N];
PII edge[N], p[N];
bool st[N];

void add_edge(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void Dijkstra(int u)
{
    memset(st, 0, sizeof st);
    RHEAP heap;

    dist[u][u] = 0;
    heap.push(MP(dist[u][u], u));
    
    while (SZ(heap))
    {
        auto t = heap.top();
        heap.pop();

        int v = t.S, d = t.F;
        st[v] = true;

        for (int i = h[v]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[u][j] > d + w[i])
            {
                dist[u][j] = d + w[i];
                heap.push(MP(dist[u][j], j));
            }
        }
    }
}

// read the question carefully!!!
int main()
{
    IOS

    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
        add_edge(b, a, c);
        edge[i] = MP(a, b);
    }

    for (int i = 0; i < k; i ++ ) cin >> p[i].F >> p[i].S;

    for (int i = 1; i <= n; i ++ ) Dijkstra(i);

    int res = 0x3f3f3f3f;
    for (int i = 0; i < m; i ++ )
    {
        int x = edge[i].F, y = edge[i].S;
        int tot = 0;
        for (int j = 0; j < k; j ++ )
        {
            int a = p[j].F, b = p[j].S;
            tot += min(dist[a][b], min(dist[a][x] + dist[y][b], dist[a][y] + dist[x][b]));
        }
        res = min(res, tot);
    }
    cout << res << '\n';
    return 0;
}
