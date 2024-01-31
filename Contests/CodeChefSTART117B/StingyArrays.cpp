/**
 * Author: C0ldSmi1e
 * Created Time: 01/17/2024 04:08:14 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START117B/problems/STINGY
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
      if ((int) stk.size() == 0 || stk.back().first != a[i]) {
        stk.emplace_back(a[i], 1);
      } else {
        stk.back().second += 1;
      }
    }
    int tot = 0;
    while ((int) stk.size() > 0) {
      debug(stk);
      int mn = n;
      for (auto& [x, y] : stk) {
        mn = min(mn, y);
      }
      tot += mn;
      vector<pair<int, int>> nstk;
      for (auto& [x, y] : stk) {
        y -= mn;
        if (y == 0) {
          continue;
        }
        if ((int) nstk.size() == 0 || nstk.back().first != x) {
          nstk.emplace_back(x, y);
        } else {
          nstk.back().second += y;
        }
      }
      swap(nstk, stk);
    }
    debug(tot);
    cout << (tot % 2 == 0 ? "Bob\n" : "Alice\n");
  }
  return 0;
}
