/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-24 06:38:11
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1901/problem/A
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
    vector<int> a{0};
    for (int i = 0; i < n; i++) {
      int y;
      cin >> y;
      a.emplace_back(y);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
      res = max(res, a[i] - a[i - 1]);
    }
    res = max(res, 2 * (x - a[n]));
    cout << res << '\n';
  }
  return 0;
}
