/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-03 06:42:56
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1902/problem/B
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
    long long n, p, l, t;
    cin >> n >> p >> l >> t;
    long long L = 0;
    long long R = n;
    auto Check = [&](long long x) -> bool {
      long long res = x * l;
      long long tn = (n + 6) / 7;
      res += t * min(2 * x, tn);
      return res >= p;
    };
    while (L < R) {
      long long mid = (L + R) >> 1;
      if (Check(mid)) {
        R = mid;
      } else {
        L = mid + 1;
      }
    }
    cout << n - R << '\n';
  }
  return 0;
}
