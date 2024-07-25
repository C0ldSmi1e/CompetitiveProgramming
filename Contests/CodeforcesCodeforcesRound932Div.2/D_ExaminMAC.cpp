/**
 * Author: C0ldSmi1e
 * Created Time: 03/08/2024 09:54:30 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1935/problem/D
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long ans = 1ll * (1 + 1 + m) * (m + 1) / 2;
    int odd = 0, even = 0;
    for (auto& u : a) {
      cin >> u;
      if (u & 1) {
        odd += 1;
      } else {
        even += 1;
      }
      ans -= (u - (u + 1) / 2 + 1) + (m - u);
    }
    ans += 1ll * odd * (odd - 1) / 2;
    ans += 1ll * even * (even - 1) / 2;
    cout << ans << '\n';
  }
  return 0;
}
