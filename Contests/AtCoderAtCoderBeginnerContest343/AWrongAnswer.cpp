/**
 * Author: C0ldSmi1e
 * Created Time: 03/07/2024 08:52:20 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc343/tasks/abc343_a
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

  int a, b;
  cin >> a >> b;
  for (int i = 0; i <= 9; i++) {
    if (i != a + b) {
      cout << i << '\n';
      break;
    }
  }
  return 0;
}
