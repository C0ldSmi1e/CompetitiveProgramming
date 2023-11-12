/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-03 09:14:22
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1895/problem/D
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> b(n);
  for (int bit = 0; n > 1 << bit; bit++) {
    vector<int> d(2);
    for (int i = 0; i < n; i++) {
      d[(i >> bit) & 1] += 1;
    }
    for (int k = 0; k <= 1; k++) {
      vector<int> c(n);
      c[0] = k;
      for (int i = 0; i < n - 1; i++) {
        c[i + 1] = (c[i] ^ ((a[i] >> bit) & 1));
      }
      int c0 = 0;
      int c1 = 0;
      for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
          c0 += 1;
        } else {
          c1 += 1;
        }
      }
      if (c0 == d[0] && c1 == d[1]) {
        for (int i = 0; i < n; i++) {
          b[i] |= (c[i] << bit);
        }
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " \n"[i == n - 1];
  }
  return 0;
}
