/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-08 07:19:36
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START107B/problems/MAXIMALEXP
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
    if (n >= k) {
      n = k + n % k;
    } else {
      n %= k;
    }
    if (n == 2 * k - 1) {
      cout << k + k / 2 << '\n';
    } else {
      cout << n / 2 << '\n';
    }
  }
  return 0;
}
