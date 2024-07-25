/**
 * Author: C0ldSmi1e
 * Created Time: 06/09/2024 03:30:10 PM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1980/problem/F1
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

  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      if (mp.count(y)) {
        if (x > mp[y].first) {
          mp[y] = make_pair(x, i);
        }
      } else {
        mp[y] = make_pair(x, i);
      }
    }
    long long mx = 0;
    int last_x = -1;
    int last_y = -1;
    vector<int> ans(k);
    debug(mp);
    for (auto& [y, info] : mp) {
      auto [x, id] = info;
      if (x > last_x) {
        debug(x, y, last_x, last_y);
        if (last_x == -1) {
          last_x = -1;
          last_y = 0;
        }
        mx += 1ll * (y - last_y) * (n - last_x - 1);
        debug(mx);
        last_x = x;
        last_y = y;
        ans[id] = 1;
      }
    }
    mx += 1ll * (m - last_y) * (n - last_x - 1);
    set<int> S;
    cout << mx << '\n';
    for (auto& u : ans) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
