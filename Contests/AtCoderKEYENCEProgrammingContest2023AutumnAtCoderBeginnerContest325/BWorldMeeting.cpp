/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-22 01:25:07
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc325/tasks/abc325_b
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  vector<int> w(n);
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> x[i];
  }
  int res = 0;
  for (int i = 0; i < 24; i++) {
    int ans = 0;
    for (int j = 0; j < n; j++) {
      int now = (i + x[j]) % 24;
      if (now >= 9 && now < 18) {
        ans += w[j];
      }
    }
    res = max(res, ans);
  }
  cout << res << '\n';
  return 0;
}
