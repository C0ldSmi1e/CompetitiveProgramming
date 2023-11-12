/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 14:20:37
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1883/problem/C
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int res = 5;
    for (auto& u : a) {
      res = min(res, (k - u % k) % k);
    }
    if (k == 4) {
      int even = 0;
      for (auto& u : a) {
        if (u % 2 == 0) {
          even += 1;
        }
      }
      res = min(res, max(0, 2 - even));
    }
    cout << res << '\n';
  }
  return 0;
}
