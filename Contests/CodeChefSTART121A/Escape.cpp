/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 07:32:02 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START121A/problems/CHEFESCAPE
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

class Dsu {
 public:
  vector<int> p, sz;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int Get(int x) {
    return (x == p[x] ? x : (p[x] = Get(p[x])));
  }
  inline bool Unite(int x, int y) {
    x = Get(x);
    y = Get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int GetSize(int x) {
    return sz[Get(x)];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> b(m);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
      cin >> b[i].first >> b[i].second;
      --b[i].first;
      --b[i].second;
      mp[b[i]] = i;
    }
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    Dsu d(m);
    for (int i = 0; i < m; i++) {
      auto [x, y] = b[i];
      for (int j = 0; j < 8; j++) {
        int tx = x + dx[j];
        int ty = y + dy[j];
        if (tx < 0 || ty < 0 || tx >= n || ty >= n) {
          continue;
        }
        pair<int, int> p = make_pair(tx, ty);
        if (mp.count(p)) {
          d.Unite(i, mp[p]);
        }
      }
    }
    vector<bool> bad(m);
    for (int i = 0; i < m; i++) {
      if (b[i].first == 0 || b[i].second == n - 1) {
        bad[d.Get(i)] = true;
      }
    }
    bool flag = true;
    for (int i = 0; i < m; i++) {
      if ((b[i].second == 0 || b[i].first == n - 1) && bad[d.Get(i)]) {
        flag = false;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
