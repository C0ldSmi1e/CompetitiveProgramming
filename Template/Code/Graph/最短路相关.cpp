// Dijkstra 算法
// O(mlogn)
typedef pair<int, int> PII;

int n;  // 点的数量
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
int dist[N];  // 存储所有点到1号点的距离
bool st[N];  // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int Dijkstra()
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // first 存储距离， second 存储节点编号
    heap.push({0, 1});      
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}



// Bellman-Ford
// 求有边数限制的最短路
// 时间复杂度为 O(nm)
int n, m;  // n表示点数，m表示边数
int dist[N];  // dist[x]存储1到x的最短路距离
int last[N];  // 备份数组
// 边，a表示出点，b表示入点，w表示边的权重
struct Edge     
{
    int a, b, w;
}edges[M];

// 求1到n的最短路距离
// 如果无法从1走到n，则返回-1。
int Bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 如果第n次迭代仍然会松弛三角不等式
    // 就说明存在一条长度是n+1的最短路径
    // 由抽屉原理，路径中至少存在两个相同的点
    // 说明图中存在负权回路。
    for (int i = 0; i < k; i ++ )
    {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; j ++ )
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}



// Spfa
// 可求有负权边的最短路
// 时间复杂度最坏为 O(nm) ，平均为 O(n)
// 非必须不用
int n;  // 总点数
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
int dist[N];  // 存储每个点到1号点的最短距离
bool st[N];  // 存储每个点是否在队列中

// 求1号点到n号点的最短路距离
// 如果从1号点无法走到 n 号点则返回 -1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                // 如果队列中已存在j
                // 则不需要将j重复插入
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}



// Spfa 判负环
// 如果卡得比较紧，可以把队列换成栈试试
// 或者若在队列里执行很多轮还没有结束，则可以视作存在负环
int n; // 总点数
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
int dist[N], cnt[N];  // dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
bool st[N];  // 存储每个点是否在队列中

// 如果存在负环，则返回true，否则返回false。
bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                // 如果从 1 号点到 x 的最短路中包含至少 n 个点（不包括自己），则说明存在环
                if (cnt[j] >= n) return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}



// Floyd
// 求任意两点之间的最短路，时间复杂度为 O(n^3)
// 主要应用：
//  1. 最短路
//  2. 求传递闭包
//  3. 找最小环
//  4. 恰好经过 k 条边的最短路
// 初始化
for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= n; j ++ )
        if (i == j) d[i][j] = 0;
		else d[i][j] = INF;

// 算法结束后，d[a][b]表示a到b的最短距离d
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}



// 最短路条数
int n, m;
cin >> n >> m;
VE<VPII> g(n);
for (int i = 0; i < m; i ++ )
{
    int a, b;
    cin >> a >> b;
    a -- , b -- ;
    g[a].EB(b, 1);
    g[b].EB(a, 1);
}
VI dist(n, INF);
VI cnt(n);
VB st(n, false);
dist[0] = 0;
cnt[0] = 1;
RHEAP<PII> heap;
heap.push(MP(0, 0));
while (SZ(heap))
{
    auto [d, u] = heap.top();
    heap.pop();
    if (st[u]) continue;
    else st[u] = true;
    for (auto &[v, w] : g[u])
    {
        if (dist[v] == dist[u] + w) cnt[v] = (cnt[v] + cnt[u]) % mod;
        else if (dist[v] > dist[u] + w)
        {
            dist[v] = dist[u] + w;
            cnt[v] = cnt[u];
            heap.push(MP(dist[v], v));
        }
    }
}
for (auto &u : cnt)
    cout << u << '\n';



// 次短路（拆点） + 最短路及恰好比最短路长 1 的次短路计数
typedef tuple<int, int, int> Point;

int Dijkstra()
{
    VE<VI> dist(n, VI(2, INF)), cnt(n, VI(2));
    VE<VB> st(n, VB(2, false));
    dist[A][0] = 0, cnt[A][0] = 1;
    RHEAP<Point> heap;
    heap.push(MT(dist[A][0], A, 0));
    while (SZ(heap))
    {
        auto [d, u, type] = heap.top();
        heap.pop();
        if (st[u][type]) continue;
        else st[u][type] = true;
        int count = cnt[u][type];
        for (auto &[v, w] : g[u])
        {
            if (dist[v][0] > d + w)
            {
                dist[v][1] = dist[v][0];
                cnt[v][1] = cnt[v][0];
                heap.push(MT(dist[v][1], v, 1));
                dist[v][0] = d + w;
                cnt[v][0] = count;
                heap.push(MT(dist[v][0], v, 0));
            }
            else if (dist[v][0] == d + w) cnt[v][0] += count;
            else if (dist[v][1] > d + w)
            {
                dist[v][1] = d + w;
                cnt[v][1] = count;
                heap.push(MT(dist[v][1], v, 1));
            }
            else if (dist[v][1] == d + w) cnt[v][1] += count;
        }
    }
    int res = cnt[B][0];
    if (dist[B][0] + 1 == dist[B][1]) res += cnt[B][1];
    return res;
}



// 第 k 短路（A*）
int main()
{
    int n, m;
    cin >> n >> m;
    VE<VPII> g(n), rg(n);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        a -- , b -- ;
        g[a].EB(b, c);
        rg[b].EB(a, c);
    }
    int S, T, k;
    cin >> S >> T >> k;
    S -- , T -- ;
    // 路径至少包含一条边的处理
    k += (int)(S == T);
    VI dist(n, INF);
    auto Dijkstra = [&](int u)
    {
        VB st(n, false);
        RHEAP<PII> heap;
        dist[u] = 0;
        heap.push(MP(dist[u], u));
        while (SZ(heap))
        {
            auto [d, u] = heap.top();
            heap.pop();
            if (st[u]) continue;
            else st[u] = true;
            for (auto &[v, w] : rg[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    heap.push(MP(dist[v], v));
                }
            }
        }
    };
    auto a_star = [&]() -> int
    {
        RHEAP<tuple<int, int, int>> heap;
        heap.push(MT(dist[S], 0, S));
        VI cnt(n);
        while (SZ(heap))
        {
            auto [xx, d, u] = heap.top();
            heap.pop();
            cnt[u] ++ ;
            if (cnt[T] == k) return d;
            for (auto &[v, w] : g[u]) 
                if (cnt[v] < k)
                    heap.push(MT(d + w + dist[v], d + w, v));
        }
        return -1;
    };
    Dijkstra(T);
    cout << a_star() << '\n';
    return 0;
}



常用技巧：缩点、拆点、建反边、虚点、二分路径长度屏蔽法（0\1）
求所有权值为 1 的最短路可以用 BFS 
