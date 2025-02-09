/**
 * Author: C0ldSmi1e
 * Created Time: 02/07/2025 09:48:25 PM
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int l = 1;
    int r = n - (k - 2);
    bool flag = false;
    for (int i = l; i < r; i++) {
      flag |= (a[i] != 1);
    }
    if (flag) {
      cout << "1\n";
      continue;
    }
    if (l + 1 < r) {
      cout << "2\n";
      continue;
    }
    int ans = 1;
    for (int i = l; i < n; i += 2) {
      if (a[i] != ans) {
        break;
      }
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}

