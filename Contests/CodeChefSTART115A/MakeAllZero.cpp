/**
 * Author: C0ldSmi1e
 * Created Time: 01/03/2024 06:48:04 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START115A/problems/MAKE0
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
    vector<int> mn(n);
    mn[0] = a[0];
    for (int i = 1; i < n; i++) {
      mn[i] = min(mn[i - 1], a[i]);
    }
    vector<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
      if ((int) stk.size() == 0 || stk.back().first > a[i]) {
        stk.emplace_back(make_pair(a[i], 1));
      } else if (stk.back().first == a[i]) {
        stk.back().second += 1;
      }
    }
    int res = n;
    int cnt = 0;
    for (int i = (int) stk.size() - 1; i >= 0; i--) {
      cnt += stk[i].second;
      res = min(res, stk[i].first + n - cnt);
    }
    cout << res << '\n';
  }
  return 0;
}
