/**
 * Author: C0ldSmi1e
 * Created Time: 02/21/2024 11:55:09 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1926/problem/D
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
    multiset<int> S{a.begin(), a.end()};
    int cnt = 0;
    for (auto& u : a) {
      if (S.find(u) == S.end()) {
        continue;
      }
      int v = (INT_MAX ^ u);
      if (S.count(v) > 0) {
        S.erase(S.find(u));
        S.erase(S.find(v));
        cnt += 1;
      }
    }
    int ans = cnt + (int) S.size();
    cout << ans << '\n';
  }
  return 0;
}
