/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-03 07:47:03
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1895/problem/B
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    int res = a[n - 1] - a[0] + a.back() - a[n];
    cout << res << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ' << a[i + n] << '\n';
    }
  }
  return 0;
}
