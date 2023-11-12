/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-07 08:22:56
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1894/problem/C
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
    int n, k;
    cin >> n >> k;
    k = min(k, n);
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    bool flag = true;
    int i = n;
    for (int it = 0; flag && it < k; it++) {
      if (a[i - 1] > n) {
        flag = false;
      } else {
        i -= a[i - 1];
        if (i <= 0) {
          i += n;
        }
      }
    }
    cout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}
