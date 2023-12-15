/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-06 07:05:36
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START111B/problems/LCMMANIA
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
    int nn = n;
    int p2 = 1;
    while (nn % 2 == 0) {
      p2 <<= 1;
      nn /= 2;
    }
    if (nn == 1) {
      cout << "-1\n";
      continue;
    }
    if (n & 1) {
      cout << "1 1 " << n / 2 << '\n';
      continue;
    }
    cout << p2 << ' ' << p2 << ' ' << p2 * (nn / 2) << '\n';
  }
  return 0;
}
