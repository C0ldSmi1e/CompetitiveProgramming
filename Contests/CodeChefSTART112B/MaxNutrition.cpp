/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-17 00:26:31
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START112B/problems/NUTRITION
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
      --u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      c[a[i]] = max(c[a[i]], b[i]);
    }
    cout << accumulate(c.begin(), c.end(), 0) << '\n';
  }
  return 0;
}
