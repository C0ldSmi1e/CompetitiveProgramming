/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-05 10:19:10
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc326/tasks/abc326_c
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

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  sort(a.begin(), a.end());
  int res = 0;
  debug(a);
  for (int i = 0, j = 0; i < n; i++) {
    while (a[i] - a[j] >= m) {
      j += 1;
    }
    debug(i, j);
    res = max(res, i - j + 1);
  }
  cout << res << '\n';
  return 0;
}
