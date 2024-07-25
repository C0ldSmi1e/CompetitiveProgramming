/**
 * Author: C0ldSmi1e
 * Created Time: 02/28/2024 06:48:41 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START123A/problems/YETALICEBOB
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
    int n, a, b;
    cin >> n >> a >> b;
    if (n <= a || a > b) {
      cout << "Alice\n";
      continue;
    }
    if (b > a) {
      cout << "Bob\n";
      continue;
    }
    assert(a == b);
    if (n % (b + 1) == 0) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }
  return 0;
}
