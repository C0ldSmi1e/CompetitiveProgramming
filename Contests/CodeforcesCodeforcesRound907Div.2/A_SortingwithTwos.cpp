/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-30 07:35:50
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1891/problem/A
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int m = 1;
    debug(a);
    while (m < n) {
      if (a[m - 1] > a[m]) {
        int d = a[m - 1] - a[m];
        for (int i = 0; i <= m - 1; i++) {
          a[i] -= d;
        }
      }
      m *= 2;
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
  }
  return 0;
}
