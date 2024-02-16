/**
 * Author: C0ldSmi1e
 * Created Time: 02/15/2024 06:35:43 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1929/problem/A
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
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
      ans += a[i] - a[i - 1];
    }
    cout << ans << '\n';
  }
  return 0;
}
