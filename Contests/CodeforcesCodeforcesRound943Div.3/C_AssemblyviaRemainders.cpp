/**
 * Author: C0ldSmi1e
 * Created Time: 05/02/2024 07:53:46 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1968/problem/C
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
    vector<int> b(n - 1);
    for (auto& u : b) {
      cin >> u;
    }
    vector<int> a(n);
    a[0] = (int) 501;
    for (int i = 1; i < n; i++) {
      a[i] = a[i - 1] + b[i - 1];
    }
    debug(a);
    for (int i = 1; i < n; i++) {
      assert(a[i] % a[i - 1] == b[i - 1]);
    }
    for (auto& u : a) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
