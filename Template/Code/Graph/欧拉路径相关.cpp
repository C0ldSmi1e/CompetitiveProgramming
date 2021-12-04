// 欧拉路径
// 找到一种路径可以遍历所有边恰好一次
const int N = 2010, M = 1010;

int n = 500, m;
int deg[N];
int g[N][N];
VI path;

void dfs(int u)
{
    for (int i = 1; i <= n; i ++ )
        if (g[u][i])
        {
            g[u][i] -- , g[i][u] -- ;
            dfs(i);
        }
    path.EB(u);
}

int main()
{
    cin >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] ++ , g[b][a] ++ ;
        deg[a] ++ , deg[b] ++ ;
    }
    int start = 1;
    while (!deg[start]) start ++ ;
    for (int i = 1; i <= n; i ++ )
        if (deg[i] & 1)
        {
            start = i;
            break;
        }
    dfs(start);
    reverse(ALL(path));
    for (auto &u : path) cout << u << '\n';
    return 0;
}



// 欧拉回路
// 即在图中找一个环使得每条边都在环上出现恰好一次
const int N = 100010, M = 4 * N;

int type;
int n, m;
int h[N], e[M], ne[M], idx;
int din[N], dout[N];
bool st[M];
VI path;

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    for (int &i = h[u]; ~i; )
    {
        int j = e[i];
        if (st[i])
        {
            i = ne[i];
            continue;
        }

        st[i] = true;
        if (type == 1) st[i ^ 1] = true;

        int t;
        if (type == 1)
        {
            t = i / 2 + 1;
            if (i & 1) t = -t;
        }
        else t = i + 1;

        i = ne[i];
        dfs(j);
        path.EB(t);
    }
}

int main()
{
    SOS;

    memset(h, -1, sizeof h);
    
    cin >> type >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        if (type == 1) add_edge(b, a);
        din[b] += 1, dout[a] += 1;
    }

    bool flag = true;
    if (type == 1)
    {
        for (int i = 1; i <= n; i ++ )
            if ((din[i] + dout[i]) & 1)
                flag = false;
    }
    else
    {
        for (int i = 1; i <= n; i ++ )
            if ((din[i] != dout[i]))
                flag = false;
    }
    if (!flag)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i ++ )
        if (h[i] != -1)
        {
            dfs(i);
            break;
        }

    if (SZ(path) != m)
    {
        cout << "NO\n";
        return 0;
    }
    else cout << "YES\n";

    reverse(ALL(path));
    for (auto &u : path) cout << u << ' ';
    cout << '\n';
    return 0;
}



// 给定若干单词连成长串使得首尾字母相同
const int N = 110, M = 1010;

int T;
int n;
int p[N];
int din[N], dout[N];
bool st[N];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> T;
    while (T -- )
    {
        memset(st, 0, sizeof st);
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        for (int i = 0; i < N; i ++ ) p[i] = i;
        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            string s;
            cin >> s;
            int a = s[0] - 'a', b = s.back() - 'a';
            dout[a] ++ , din[b] ++ ;
            p[find(a)] = find(b);
            st[a] = st[b] = true;
        }
        bool flag = true;
        int root = -1;
        for (int i = 0; i < 26; i ++ )
            if (st[i])
            {
                if (root == -1) root = find(i);
                else if (root != find(i)) flag = false;
            }
        int start = 0, end = 0;
        for (int i = 0; i < 26; i ++ )
            if (st[i])
            {
                if (din[i] == dout[i] + 1) end ++ ;
                else if (din[i] + 1 == dout[i]) start ++ ;
                else if (din[i] != dout[i]) flag = false;
            }
        if (flag && (start == 1 && end == 1 || start == 0 && end == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
