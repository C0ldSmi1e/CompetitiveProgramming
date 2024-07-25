/**
 * Author: C0ldSmi1e
 * Created Time: 03/12/2024 11:15:28 PM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1941/problem/F
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
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<long long> b(m);
    for (auto& u : b) {
      cin >> u;
    }
    vector<long long> c(k);
    for (auto& u : c) {
      cin >> u;
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long mx = 0;
    int cnt = 0;
    int al = -1, ar = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] > mx) {
        mx = a[i] - a[i - 1];
        cnt = 1;
        al = a[i - 1];
        ar = a[i];
      } else if (a[i] - a[i - 1] == mx) {
        cnt += 1;
      }
    }
    if (cnt > 1) {
      cout << mx << '\n';
      continue;
    }
    auto Check = [&](long long x) -> bool {
      for (int i = 0; i < m; i++) {
        // b[i] + c[j] => [ar - x, al + x]
        int j = (int) (lower_bound(c.begin(), c.end(), ar - x - b[i]) - c.begin());
        if (j < k && b[i] + c[j] <= al + x) {
          return true;
        }
      }
      return false;
    };
    long long l = 0, r = mx;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (Check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    long long mn = r;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] != mx) {
        ans = max(ans, a[i] - a[i - 1]);
      } else {
        ans = max(ans, mn);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
