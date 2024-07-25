/**
 * Author: C0ldSmi1e
 * Created Time: 03/07/2024 08:55:35 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc343/tasks/abc343_b
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

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        cout << j + 1 << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
