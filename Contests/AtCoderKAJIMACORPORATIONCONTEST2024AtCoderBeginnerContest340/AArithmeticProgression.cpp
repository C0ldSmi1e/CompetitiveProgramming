/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 10:45:12 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc340/tasks/abc340_a
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

  int l, r, d;
  cin >> l >> r >> d;
  for (int i = l; i <= r; i += d) {
    cout << i << ' ';
  }
  return 0;
}
