/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 16:43:39
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1883/problem/G1
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = n;
    debug(a);
    debug(b);
    for (int i = 0, j = 0; i < n && j < n; i++) {
      while (j < n && a[i] >= b[j]) {
        j += 1;
      }
      debug(i, j);
      if (j < n) {
        res -= 1;
        j += 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
