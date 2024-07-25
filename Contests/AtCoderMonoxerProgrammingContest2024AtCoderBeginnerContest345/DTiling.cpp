/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 10:30:17 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc345/tasks/abc345_d
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, r, c;
  cin >> n >> r >> c;
  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) {
    cin >> x >> y;
  }
  vector<bool> used(n);
  vector<vector<bool>> st(r, vector<bool>(c));
  auto Place = [&](int i, int x, int y, int t) -> bool {
    auto [xx, yy] = a[i];
    if (t == 1) {
      swap(xx, yy);
    }
    if (x + xx - 1 >= r || y + yy - 1 >= c) {
      return false;
    }
    for (int i = 0; i < xx; i++) {
      for (int j = 0; j < yy; j++) {
        if (st[x + i][y + j]) {
          return false;
        }
      }
    }
    return true;
  };
  auto Flip = [&](int i, int x, int y, int t) -> void {
    auto [xx, yy] = a[i];
    if (t == 1) {
      swap(xx, yy);
    }
    for (int i = 0; i < xx; i++) {
      for (int j = 0; j < yy; j++) {
        st[x + i][y + j] = !st[x + i][y + j];
      }
    }
  };
  auto Dfs = [&](auto& self, int x, int y) -> bool {
    //debug(x, y);
    //debug(used);
    //for (int i = 0; i < r; i++) {
    //  for (int j = 0; j < c; j++) {
    //    cout << st[i][j] << " \n"[j == c - 1];
    //  }
    //}
    if (x >= r) {
      return true;
    }
    if (y >= c) {
      return self(self, x + 1, y = 0);
    }
    if (st[x][y]) {
      return self(self, x, y + 1);
    }
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        if (Place(i, x, y, 0)) {
          used[i] = true;
          Flip(i, x, y, 0);
          if (self(self, x, y + 1)) {
            return true;
          }
          Flip(i, x, y, 0);
          used[i] = false;
        }
        if (Place(i, x, y, 1)) {
          used[i] = true;
          Flip(i, x, y, 1);
          if (self(self, x, y + 1)) {
            return true;
          }
          Flip(i, x, y, 1);
          used[i] = false;
        }
      }
    }
    return false;
  };
  cout << (Dfs(Dfs, 0, 0) ? "Yes\n" : "No\n");
  return 0;
}
