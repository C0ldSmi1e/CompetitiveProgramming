/**
 * Author: C0ldSmi1e
 * Created Time: 04/07/2025 09:07:31 PM
**/

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    debug(a);
    for (int i = 0; i < n; i++) {
      long long cur = 0;
      int j = i;
      while (j < n && cur < x) {
        cur = 1ll * (j - i + 1) * a[j];
        j += 1;
      }
      if (cur >= x) {
        ans += 1;
      }
      i = j - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
