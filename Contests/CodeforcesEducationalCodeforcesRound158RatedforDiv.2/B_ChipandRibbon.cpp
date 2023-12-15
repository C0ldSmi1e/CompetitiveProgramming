/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-24 06:44:58
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1901/problem/B
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
    long long res = 0;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && a[j] > 0) {
        j += 1;
      }
      for (int k = i; k < j; k++) {
        res += max(0, a[k] - (k - 1 >= 0 ? a[k - 1] : 0));
      }
      debug(i, j);
      i = j;
    }
    cout << res - 1 << '\n';
  }
  return 0;
}
