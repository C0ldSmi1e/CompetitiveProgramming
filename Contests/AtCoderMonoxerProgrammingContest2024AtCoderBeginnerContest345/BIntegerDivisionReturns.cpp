/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 09:50:44 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc345/tasks/abc345_b
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

  long long x;
  cin >> x;
  if (x >= 0) {
    cout << (x + 9) / 10 << '\n';
  } else {
    cout << x / 10 << '\n';
  }
  return 0;
}
