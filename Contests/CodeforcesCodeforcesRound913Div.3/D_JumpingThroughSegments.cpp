/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 07:42:07
**/

// time-limit: 5000
// problem-url: https://codeforces.com/contest/1907/problem/D
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
    vector<long long> l(n);
    vector<long long> r(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    auto Check = [&](long long k) -> bool {
      long long L = 0;
      long long R = 0;
      for (int i = 0; i < n; i++) {
        L -= k;
        R += k;
        L = max(L, l[i]);
        R = min(R, r[i]);
        if (L > R) {
          return false;
        }
      }
      return true;
    };
    long long lo = 0, hi = (long long) 1e18;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      if (Check(mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << hi << '\n';
  }
  return 0;
}
