/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-11 15:07:26
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc332/tasks/abc332_d
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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> src(n, vector<int>(m));
  vector<vector<int>> dst(n, vector<int>(m));
  for (auto& u : src) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  for (auto& u : dst) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  map<vector<vector<int>>, int> mp;
  vector<vector<vector<int>>> q;
  q.emplace_back(src);
  mp[src] = 0;
  for (int qq = 0; qq < (int) q.size(); qq++) {
    auto g = q[qq];
    if (g == dst) {
      break;
    }
    for (int i = 0; i < n - 1; i++) {
      auto nxt = g;
      swap(nxt[i], nxt[i + 1]);
      if (!mp.count(nxt)) {
        mp[nxt] = mp[g] + 1;
        q.emplace_back(nxt);
      }
    }
    for (int j = 0; j < m - 1; j++) {
      auto nxt = g;
      for (int i = 0; i < n; i++) {
        swap(nxt[i][j], nxt[i][j + 1]);
      }
      if (!mp.count(nxt)) {
        mp[nxt] = mp[g] + 1;
        q.emplace_back(nxt);
      }
    }
  }
  if (mp.count(dst)) {
    cout << mp[dst] << '\n';
  } else {
    cout << "-1\n";
  }
  return 0;
}
