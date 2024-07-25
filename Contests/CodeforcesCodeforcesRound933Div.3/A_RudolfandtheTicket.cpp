/**
 * Author: C0ldSmi1e
 * Created Time: 03/12/2024 04:46:35 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1941/problem/A
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(m);
    for (auto& u : b) {
      cin >> u;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans += (int) (a[i] + b[j] <= k);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
