/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 06:51:42
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1899/problem/C
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int res = *max_element(a.begin(), a.end());
    int i = 0;
    int t = -1;
    int cur = 0;
    while (i < n) {
      if (t == -1) {
        cur += a[i];
        if (a[i] % 2 == 0) {
          t = 1;
        } else {
          t = 0;
        }
      } else if (abs(a[i] % 2) == t) {
        cur += a[i];
        t ^= 1;
      } else {
        cur = 0;
        t = -1;
        continue;
      }
      res = max(res, cur);
      if (cur < 0) {
        cur = 0;
        t = -1;
      }
      i += 1;
    }
    cout << res << '\n';
  }
  return 0;
}
