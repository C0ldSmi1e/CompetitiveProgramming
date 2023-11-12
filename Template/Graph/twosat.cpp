// x[] 有 n 个元素，给定 m 个条件
// 每个条件为： 使得 x[i] 为 0/1 或 x[j] 为 0/1 至少有一项成立
// 寻找一组解
class TwoSat {
 public:
  // i is in [0, n - 1]
  // 2 * i indicates (i == 0)
  // 2 * i + 1 indicates (i == 1)
  int n;
  vector<vector<int>> g;

  TwoSat(int _n) : n(_n), g(vector<vector<int>>(2 * _n)) {}

  inline void add(int x, int valX) {
    // (v[x] == valX)
    // add an edge: (!x, x)
    assert(x >= 0 && x < n);
    assert(valX >= 0 && valX <= 1);
    g[2 * x + (valX ^ 1)].emplace_back(2 * x + valX);
  }

  inline void add(int x, int valX, int y, int valY) {
    // (v[x] == valX || v[y] == valY)
    // add edges: (!x, y) and (!y, x)
    assert(x >= 0 && x < n && y >= 0 && y < n);
    assert(valX >= 0 && valX <= 1 && valY >= 0 && valY <= 1);
    g[2 * x + (valX ^ 1)].emplace_back(2 * y + valY);
    g[2 * y + (valY ^ 1)].emplace_back(2 * x + valX);
  }

  vector<int> findSCC(int &id) {
    int top = 0, n = (int) g.size();
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

  inline vector<int> get() {
    // if there is no answer, then return a void vector
    int cnt = 0;
    vector<int> comp = findSCC(cnt);
    assert((int) comp.size() == 2 * n);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (comp[2 * i] == comp[2 * i + 1]) {
        return vector<int>();
      }
      res[i] = (((int) (comp[2 * i] < comp[2 * i + 1])) ^ 1);
    }
    return res;
  }
};
