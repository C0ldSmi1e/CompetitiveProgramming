void Tarjan(int u, int fa) {
  dfn[u] = low[u] = time_stamp++;
  int son_cnt = 0;
  // id is edge's id
  for (auto& [v, id] : g[u]) {
    if (v != fa) {
      if (dfn[v] == -1) {
        son_cnt += 1;
        Dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > dfn[u]) {
          // id is a bridge
        }
        if (fa != -1 && low[v] >= dfn[u]) {
          // u is not root, and u is a cut vertex
        }
      } else {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  if (fa == -1 && son_cnt > 1) {
    // u is root, and u is a cut vertex
  }
}
