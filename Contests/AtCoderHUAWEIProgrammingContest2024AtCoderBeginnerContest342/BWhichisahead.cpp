/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 03:11:03 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc342/tasks/abc342_b
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
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    b[a[i]] = i;
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    if (b[l] > b[r]) {
      cout << r + 1 << '\n';
    } else {
      cout << l + 1 << '\n';
    }
  }
  return 0;
}
