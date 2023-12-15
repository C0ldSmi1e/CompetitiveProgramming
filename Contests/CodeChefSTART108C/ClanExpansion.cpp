/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-15 07:28:09
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START108C/problems/CLANEXPNSN
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    for (auto& u : a) {
      cin >> u;
      --u;
      m = max(m, u);
    }
    m += 1;
    vector<vector<int>> idx(m);
    for (int i = 0; i < n; i++) {
      idx[a[i]].emplace_back(i);
    }
    int res = n;
    int id = -1;
    for (int x = 0; x < m; x++) {
      if ((int) idx[x].size() == 0) {
        continue;
      }
      if ((int) idx[x].size() == 1) {
        int ans = max(idx[x][0], n - idx[x][0] - 1);
        debug(ans, idx[x]);
        if (ans < res) {
          res = ans;
          id = x + 1;
        }
        continue;
      }
      int ans = max(idx[x][0], n - idx[x].back() - 1);
      for (int i = 0; i < (int) idx[x].size() - 1; i++) {
        ans = max(ans, (idx[x][i + 1] - idx[x][i]) / 2);
      }
      if (ans < res) {
        res = ans;
        id = x + 1;
      }
    }
    cout << id << ' ' << res << '\n';
  }
  return 0;
}
