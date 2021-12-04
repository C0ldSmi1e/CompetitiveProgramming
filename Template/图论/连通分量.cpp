// 强连通分量






const int N = 100010, M = 1010;

int n;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, scc_size[N], id[N];
int din[N], dout[N];

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (low[u] == dfn[u])
    {
        int y;
        scc_cnt ++ ;
        do
        {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            scc_size[scc_cnt] ++ ;
        } while (y != u);
    }
}

int main()
{
    SOS;

    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
    {
        int t;
        while (cin >> t, t) add_edge(i, t);
    }

    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i);

    for (int u = 1; u <= n; u ++ )
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            int a = id[u], b = id[j];
            if (a != b) dout[a] ++ , din[b] ++ ;
        }

    int st = 0, ed = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
    {
        if (!din[i]) st ++ ;
        if (!dout[i]) ed ++ ;
    }

    cout << st << '\n';
    if (scc_cnt == 1) cout << "0\n";
    else cout << max(st, ed) << '\n';
    return 0;
}

vector<int> findSCC(const vector<vector<int>> g, int &id) {
  int n = static_cast<int>(g.size());
  int top = 0;
  vector<int> comp(n, -1), in(n, -1), out(n, -1), stk(n + 1, -1), order;
  function<int(int u)> tarjan = [&](int u) -> int {
    assert(top >= 0 && top <= n);
    stk[top++] = u;
    int low = in[u] = (int) order.size();
    order.push_back(u);
    for (auto &v : g[u]) {
      if (in[v] == -1) {
        low = min(low, tarjan(v));
        continue;
      }
      if (comp[v] == -1) {
        low = min(low, in[v]);
      }
    }
    if (low == in[u]) {
      while (stk[top] != u) {
        assert(top >= 0 && top <= n);
        comp[stk[--top]] = id;
      }
      id++;
    }
    out[u] = (int) order.size() - 1;
    return low;
  };
  for (int i = 0; i < n; i++) {
    if (in[i] == -1) {
      tarjan(i);
    }
  }
  return comp;
}



const int N = 100010, M = 1010;

int n, m;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, scc_size[N];
int din[N], dout[N];

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        int y;
        scc_cnt ++ ;
        do
        {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            scc_size[scc_cnt] ++ ;
        } while (y != u);
    }
}

int main()
{
    SOS;

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }

    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i);

    for (int u = 1; u <= n; u ++ )
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            int a = id[u], b = id[j];
            if (a != b) din[b] ++ , dout[a] ++ ;
        }

    int cnt = 0, res = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
        if (!dout[i])
        {
            cnt ++ ;
            res = scc_size[i];
        }

    if (cnt == 1) cout << res << '\n';
    else cout << "0\n";
    return 0;
}
