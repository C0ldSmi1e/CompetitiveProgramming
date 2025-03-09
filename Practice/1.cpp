/**
 * Author: C0ldSmi1e
 * Created Time: 03/09/2025 06:57:24 AM
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int l = -1;
    int r = -1;
    for (int i = 1; i < n - 1; i++) {
      int j = i + 1;
      while (j < n && 1ll * (a[j] - a[j - 1]) * (a[i + 1] - a[i]) > 0) {
        j += 1;
      }
      debug(i, j, a[i - 1], a[i], a[i + 1]);
      if (j >= n) {
        break;
      }
      if (1ll * (a[i] - a[i - 1]) * (a[i + 1] - a[i]) < 0) {
        l = i - 1;
        r = j;
        break;
      }
      i = j - 1;
    }
    if (l == -1 || r == -1) {
      cout << "-1\n";
      continue;
    }
    cout << l + 1 << ' ' << r + 1 << '\n';
  }
  return 0;
}
