/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-24 07:02:36
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1917/problem/C
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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(k);
    for (auto& u : b) {
      cin >> u;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
      res += (int) (i + 1 == a[i]);
    }
    res += (d - 1) / 2;
    debug(res);
    for (int i = 0; i < max(n, k) && i + 2 <= d; i++) {
      long long ans = (d - (i + 2)) / 2;
      for (int j = 0; j < b[i % k]; j++) {
        a[j] += 1;
      }
      for (int i = 0; i < n; i++) {
        ans += (int) (i + 1 == a[i]);
      }
      debug(ans);
      res = max(res, ans);
    }
    cout << res << '\n';
  }
  return 0;
}
