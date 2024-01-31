/**
 * Author: C0ldSmi1e
 * Created Time: 01/17/2024 06:36:27 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START117B/problems/NPRPE
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
    vector<int> p(n);
    for (auto& u : p) {
      cin >> u;
    }
    if (n <= 2) {
      cout << "-1\n";
      continue;
    }
    vector<int> a(n);
    if (n & 1) {
      int t = n + 1;
      for (int i = 0; i < n; i++) {
        a[i] = t - p[i];
      }
    } else {
      int t = n;
      for (int i = 0; i < n; i++) {
        if (p[i] == n) {
          a[i] = n;
        } else {
          a[i] = t - p[i];
        }
      }
    }
    for (auto& u : a) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
