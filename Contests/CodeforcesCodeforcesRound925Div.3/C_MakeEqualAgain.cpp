/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 06:47:16 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1931/problem/C
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int l = 0, r = n - 1;
    while (l < n && a[l] == a[0]) {
      l += 1;
    }
    while (r >= 0 && a[r] == a.back()) {
      r -= 1;
    }
    if (l >= n) {
      cout << "0\n";
      continue;
    }
    if (a[0] == a[n - 1]) {
      cout << n - l - (n - r - 1) << '\n';
      continue;
    }
    cout << n - max(l, n - r - 1) << '\n';
  }
  return 0;
}
