/**
 * Author: C0ldSmi1e
 * Created Time: 06/08/2024 09:22:47 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1980/problem/D
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
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
      b[i] = gcd(a[i], a[i + 1]);
    }
    vector<bool> x(n);
    x[0] = x[1] = true;
    for (int i = 2; i < n; i++) {
      x[i] = x[i - 1] && b[i - 1] >= b[i - 2];
    }
    vector<bool> y(n);
    y[n - 1] = y[n - 2] = true;
    for (int i = n - 3; i >= 0; i--) {
      y[i] = y[i + 1] && b[i] <= b[i + 1];
    }
    if (x[n - 2] || y[1]) {
      cout << "YES\n";
      continue;
    }
    bool flag = false;
    for (int i = 1; i < n - 1; i++) {
      // remove a[i]
      int g = gcd(a[i - 1], a[i + 1]);
      bool ok = true;
      if (!x[i - 1] || !y[i + 1]) {
        ok = false;
      }
      int L = (i > 1 ? b[i - 2] : 0);
      int R = (i + 2 < n ? b[i + 1] : (int) 1e9);
      if (!(L <= g && g <= R)) {
        ok = false;
      }
      flag |= ok;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
