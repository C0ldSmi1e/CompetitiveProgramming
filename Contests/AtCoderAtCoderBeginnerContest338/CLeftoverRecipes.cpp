/**
 * Author: C0ldSmi1e
 * Created Time: 01/30/2024 02:45:58 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc338/tasks/abc338_c
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
  vector<long long> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<long long> b(n);
  for (auto& u : b) {
    cin >> u;
  }
  vector<long long> c(n);
  for (auto& u : c) {
    cin >> u;
  }
  long long res = 0;
  for (int i = 0; ; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      ok &= i * b[j] <= a[j];
    }
    if (!ok) {
      break;
    }
    long long mn = (long long) 1e18;
    for (int j = 0; j < n; j++) {
      if (c[j] != 0) {
        mn = min(mn, (a[j] - i * b[j]) / c[j]);
      }
    }
    res = max(res, i + mn);
  }
  cout << res << '\n';
  return 0;
}
