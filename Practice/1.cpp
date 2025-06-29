/**
 * Author: C0ldSmi1e
 * Created Time: 06/28/2025 10:27:20 PM
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
    const int INF = (int) 1e9;
    int ans = INF;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        int mn = INF;
        int mx = -INF;
        int cnt = 0;
        bool flag = false;
        for (int j = i - 1; j >= 0; j--) {
          mn = min(mn, a[j]);
          mx = max(mx, a[j]);
          int l = a[i] - 1;
          int r = a[i] + 1;
          if (max(l, mn) <= min(r, mx)) {
            flag = true;
            break;
          }
          cnt += 1;
        }
        if (flag) {
          ans = min(ans, cnt);
        }
      }
      if (i + 1 < n) {
        int mn = INF;
        int mx = -INF;
        int cnt = 0;
        bool flag = false;
        for (int j = i + 1; j < n; j++) {
          mn = min(mn, a[j]);
          mx = max(mx, a[j]);
          int l = a[i] - 1;
          int r = a[i] + 1;
          if (max(l, mn) <= min(r, mx)) {
            flag = true;
            break;
          }
          cnt += 1;
        }
        if (flag) {
          ans = min(ans, cnt);
        }
      }
    }
    if (ans == INF) {
      ans = -1;
    }
    cout << ans << '\n';
  }
  return 0;
}
