/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-26 16:27:52
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc334/tasks/abc334_a
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
  cout << (a > b ? "Bat" : "Glove");
  return 0;
}
