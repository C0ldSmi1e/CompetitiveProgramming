/**
 * Author: C0ldSmi1e
 * Created Time: 03/13/2024 08:36:52 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START125A/problems/ATBO
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
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        continue;
      }
      if (i + 3 < n) {
        a[i] += a[i + 1] + a[i + 2];
        a[i + 3] += a[i + 1] + a[i + 2];
        swap(a[i + 1], a[i + 2]);
        a[i + 1] *= -1;
        a[i + 2] *= -1;
        if (a[i] != b[i]) {
          flag = false;
          break;
        }
        continue;
      }
      flag = false;
      break;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
