/**
 * Author: C0ldSmi1e
 * Created Time: 03/12/2024 10:10:52 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1941/problem/B
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
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) {
        flag = false;
        break;
      }
      if (a[i] > 0) {
        if (i + 2 < n) {
          a[i + 2] -= a[i];
          a[i + 1] -= 2 * a[i];
          a[i] = 0;
        } else {
          flag = false;
          break;
        }
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
