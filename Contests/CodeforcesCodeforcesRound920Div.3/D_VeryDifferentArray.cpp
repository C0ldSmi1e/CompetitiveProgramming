/**
 * Author: C0ldSmi1e
 * Created Time: 01/15/2024 06:55:11 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1921/problem/D
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
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(m);
    for (auto& u : b) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long res = 0;
    for (int i = 0; i < n; i++) {
      res += abs(a[i] - b[m - i - 1]);
    }
    for (int i = 1; i <= n; i++) {
      long long ans = res;
      ans -= abs(a[n - i] - b[m - (n - i) - 1]);
      ans += abs(a[n - i] - b[i - 1]);
      res = max(res, ans);
    }
    cout << res << '\n';
  }
  return 0;
}
