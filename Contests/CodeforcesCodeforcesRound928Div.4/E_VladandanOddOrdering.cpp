/**
 * Author: C0ldSmi1e
 * Created Time: 02/21/2024 04:50:42 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1926/problem/E
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
    long long n, k;
    cin >> n >> k;
    long long x = 1;
    while (true) {
      long long take = n - n / 2;
      if (take >= k) {
        cout << (2 * k - 1) * x << '\n';
        break;
      }
      n -= take;
      k -= take;
      x <<= 1;
    }
  }
  return 0;
}
