/**
 * Author: C0ldSmi1e
 * Created Time: 01/13/2024 07:09:29 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1920/problem/C
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
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> lens;
    for (int i = 1; i <= n / i; i++) {
      if (n % i == 0) {
        lens.emplace_back(i);
        if (i != n / i) {
          lens.emplace_back(n / i);
        }
      }
    }
    int res = 0;
    for (auto& len : lens) {
      int g = 0;
      for (int i = 0; i + len < n; i++) {
        g = gcd(g, abs(a[i + len] - a[i]));
      }
      if (g != 1) {
        res += 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
