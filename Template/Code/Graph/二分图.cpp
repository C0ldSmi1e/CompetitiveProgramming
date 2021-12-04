一个图是二分图等价于这个图不存在奇数环等价于用染色法染色不存在矛盾

最大匹配等价于不存在增广路径

最小点覆盖定义：选出最少的点集，使得每条边至少有一个端点被选

最大独立集定义：选最多的点，使得点之间没有边

最大团定义：选最多的点，使得任意两点之间有边

最大匹配数=最小点覆盖=总点数-最大独立集=总点数-最小路径覆盖

求最大独立集等价于通过去掉最少的点，破坏所有的边，等价于找最小点覆盖，等价于最大匹配

最小路径点覆盖定义：用最少的互不相交（点和边均不重）的路径把所有点覆盖

最小路径重复点覆盖定义：和上一定义类似，但点和边可以重复

求最小路径重复点覆盖方法：求传递闭包，然后求最小路径点覆盖



// 染色法判断二分图
// 时间复杂度为 O(n+m)
int n;  // n 表示点数
int h[N], e[M], ne[M], idx;  // 邻接表存储图
int color[N];  // 表示每个点的颜色， -1 表示为染色， 0 表示白色， 1 表示黑色

// 参数： u 表示当前节点， c 表示当前点的颜色
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (color[j] == -1)
        {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c) return false;
    }

    return true;
}

bool check()
{
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (color[i] == -1)
            if (!dfs(i, 0))
            {
                flag = false;
                break;
            }
    return flag;
}



// 匈牙利算法
// 时间复杂度最坏为 O(nm)
// 但一般较快
// n1 表示第一个集合中的点数， n2 表示第二个集合中的点数
int n1, n2;
// 邻接表存储所有边，匈牙利算法中只会用到从第一个集合指向第二个集合的边，所以这里只用存一个方向的边
int h[N], e[M], ne[M], idx;
// 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
int match[N];
// 表示第二个集合中的每个点是否已经被遍历过
bool st[N];

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

// 求最大匹配数，依次枚举第一个集合中的每个点能否匹配第二个集合中的点
int res = 0;
for (int i = 1; i <= n1; i ++ )
{
    memset(st, false, sizeof st);
    if (find(i)) res ++ ;
}
