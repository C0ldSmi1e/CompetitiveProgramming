/**
 * Author: C0ldSmi1e
 * Created Time: 01/26/2026 09:37:33 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2185/problem/C
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
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int len = 1;
      while (j < n && a[j] - a[j - 1] <= 1) {
        if (a[j] > a[j - 1]) {
          len += 1;
        }
        j += 1;
      }
      // debug(i, j, len);
      ans = max(ans, len);
      i = j - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
