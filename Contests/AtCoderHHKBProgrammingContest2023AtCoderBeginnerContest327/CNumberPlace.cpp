/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-04 05:10:59
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc327/tasks/abc327_c
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n = 9;
  vector<vector<int>> g(n, vector<int>(n));
  for (auto& u : g) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  bool flag = true;
  {
    for (int i = 0; i < n; i++) {
      set<int> r;
      set<int> c;
      for (int j = 0; j < n; j++) {
        r.insert(g[i][j]);
        c.insert(g[j][i]);
      }
      flag &= ((int) r.size() == 9);
      flag &= ((int) c.size() == 9);
    }
  }
  {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        set<int> S;
        for (int x = 0; x < 3; x++) {
          for (int y = 0; y < 3; y++) {
            S.insert(g[3 * i + x][3 * j + y]);
          }
        }
        flag &= ((int) S.size() == 9);
      }
    }
  }
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}
