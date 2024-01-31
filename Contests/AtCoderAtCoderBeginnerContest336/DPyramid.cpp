/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 02:50:36 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc336/tasks/abc336_d
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
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> l(n);
  l[0] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      l[i] = l[i - 1] + 1;
    } else {
      l[i] = min(a[i], l[i - 1] + 1);
    }
  }
  vector<int> r(n);
  r[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      r[i] = r[i + 1] + 1;
    } else {
      r[i] = min(a[i], r[i + 1] + 1);
    }
  }
  debug(l);
  debug(r);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = min(l[i], r[i]);
  }
  cout << *max_element(b.begin(), b.end()) << '\n';
  return 0;
}
