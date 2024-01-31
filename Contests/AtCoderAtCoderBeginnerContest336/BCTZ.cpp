/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 02:00:13 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc336/tasks/abc336_b
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
  cout << __builtin_ctz(n) << '\n';
  return 0;
}
