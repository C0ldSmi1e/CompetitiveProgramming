/**
 * Author: C0ldSmi1e
 * Created Time: 01/12/2024 10:17:06 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START116B/problems/CHEFPRODUCT
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
    long long n;
    cin >> n;
    long long l = 1, r = (long long) 2e9;
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      if ((1 + 1 + (mid - 1) * 2) * mid / 2 <= n) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    long long d = n - (1 + 1 + (r - 1) * 2) * r / 2;
    if (n & 1) {
      if (d & 1) {
        cout << r / 2 << '\n';
      } else {
        cout << (r + 1) / 2 << '\n';
      }
    } else {
      cout << r / 2 << '\n';
    }
  }
  return 0;
}
