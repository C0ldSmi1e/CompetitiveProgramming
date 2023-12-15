/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-11 10:46:14
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc332/tasks/abc332_a
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

  int n, s, k;
  cin >> n >> s >> k;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int p, q;
    cin >> p >> q;
    tot += q * p;
  }
  if (tot < s) {
    tot += k;
  }
  cout << tot << '\n';
  return 0;
}
