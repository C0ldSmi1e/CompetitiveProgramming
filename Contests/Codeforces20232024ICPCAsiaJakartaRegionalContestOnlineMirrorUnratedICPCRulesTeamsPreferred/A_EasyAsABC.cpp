/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-07 15:06:46
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1906/problem/A
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

  vector<string> g(3);
  for (auto& s : g) {
    cin >> s;
  }
  int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  vector<vector<bool>> st(3, vector<bool>(3));
  set<string> S;
  auto Dfs = [&](auto& self, int x, int y, string s) -> void {
    st[x][y] = true;
    s += g[x][y];
    if ((int) s.size() == 3) {
      S.insert(s);
      s.pop_back();
      st[x][y] = false;
      return;
    }
    for (int i = 0; i < 8; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx < 0 || tx >= 3 || ty < 0 || ty >= 3) {
        continue;
      }
      if (st[tx][ty]) {
        continue;
      }
      self(self, tx, ty, s);
    }
    st[x][y] = false;
  };
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Dfs(Dfs, i, j, "");
    }
  }
  cout << *S.begin() << '\n';
  return 0;
}
