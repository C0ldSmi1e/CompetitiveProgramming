/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 03:18:34 PM
**/

// time-limit: 5000
// problem-url: https://atcoder.jp/contests/abc336/tasks/abc336_f
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

  auto Rotate = [&](vector<vector<int>>& g, int i1, int j1, int i2, int j2) -> void {
    for (int i = i1, ii = i2; i <= ii; i++, ii--) {
      if (i == ii) {
        for (int j = j1, jj = j2; j <= jj; j++, jj--) {
          swap(g[i][j], g[ii][jj]);
        }
      } else {
        for (int j = j1, jj = j2; j <= j2; j++, jj--) {
          swap(g[i][j], g[ii][jj]);
        }
      }
    }
  };
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (auto& u : g) {
    for (auto& v : u) {
      cin >> v;
      --v;
    }
  }
  vector<vector<int>> target(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      target[i][j] = i * m + j;
    }
  }
  map<vector<vector<int>>, int> mp;
  mp[g] = 0;
  {
    vector<vector<vector<int>>> q;
    q.emplace_back(g);
    for (int qq = 0; qq < (int) q.size(); qq++) {
      auto G = q[qq];
      int dist = mp[G];
      for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
          Rotate(G, i, j, i + n - 2, j + m - 2);
          if (!mp.count(G) && dist < 10) {
            q.emplace_back(G);
            mp[G] = dist + 1;
          }
          Rotate(G, i, j, i + n - 2, j + m - 2);
        }
      }
    }
  }
  const int INF = (int) 1e9;
  int res = INF;
  {
    vector<vector<vector<int>>> q;
    q.emplace_back(target);
    map<vector<vector<int>>, int> mpp;
    for (int qq = 0; qq < (int) q.size(); qq++) {
      auto G = q[qq];
      int dist = mpp[G];
      if (mp.count(G)) {
        res = min(res, dist + mp[G]);
      }
      for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
          Rotate(G, i, j, i + n - 2, j + m - 2);
          if (!mpp.count(G) && dist < 10) {
            q.emplace_back(G);
            mpp[G] = dist + 1;
          }
          Rotate(G, i, j, i + n - 2, j + m - 2);
        }
      }
    }
  }
  if (res == INF) {
    res = -1;
  }
  cout << res << '\n';
  return 0;
}
