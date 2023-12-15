/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-22 06:36:37
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START109B/problems/MINMXOR
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
    int t = 0;
    for (auto& u : a) {
      cin >> u;
      t ^= u;
    }
    int res = t;
    for (auto& u : a) {
      res = min(res, t ^ u);
    }
    cout << res << '\n';
  }
  return 0;
}
