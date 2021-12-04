#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 4 * N, K = 51, INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N][K];
int st[N][K];

struct Node
{
    int dist, u, s;
    bool operator<(const Node &t) const
    {
        return dist > t.dist;
    }
};

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        auto add_edge = [&](int a, int b, int c)
        {
            e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
        };
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    auto Dijkstra = [&]()
    {
        memset(dist, 0x3f, sizeof dist);
        priority_queue<Node> heap;
        dist[1][0] = 0;
        heap.push({0, 1, 0});
        while (heap.size())
        {
            auto [d, u, s] = heap.top();
            heap.pop();
            if (st[u][s]) continue;
            else st[u][s] = true;
            if (s)
            {
                for (int i = h[u]; ~i; i = ne[i])
                {
                    int j = e[i];
                    if (dist[j][0] > dist[u][s] + (s + w[i]) * (s + w[i]))
                    {
                        dist[j][0] = dist[u][s] + (s + w[i]) * (s + w[i]);
                        heap.push({dist[j][0], j, 0});
                    }
                }
            }
            else
            {
                for (int i = h[u]; ~i; i = ne[i])
                {
                    int j = e[i];
                    if (dist[j][w[i]] > dist[u][s])
                    {
                        dist[j][w[i]] = dist[u][s];
                        heap.push({dist[j][w[i]], j, w[i]});
                    }
                }
            }
        }
    };
    Dijkstra();
    for (int i = 1; i <= n; i ++ )
    {
        if (dist[i][0] == INF) dist[i][0] = -1;
        cout << dist[i][0] << " \n"[i == n];
    }
    return 0;
}
