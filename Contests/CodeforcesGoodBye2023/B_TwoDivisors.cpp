/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-30 07:01:08
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1916/problem/B
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
    long long a, b;
    cin >> a >> b;
    if (b % a != 0) {
      cout << a / gcd(a, b) * b << '\n';
    } else {
      cout << b * (b / a) << '\n';
    }
  }
  return 0;
}
