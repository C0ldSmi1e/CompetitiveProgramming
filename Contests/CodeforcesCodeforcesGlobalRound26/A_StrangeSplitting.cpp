/**
 * Author: C0ldSmi1e
 * Created Time: 06/10/2024 03:46:36 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1984/problem/A
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
    if (a[0] == a.back()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (i == 1) {
        cout << "R";
      } else {
        cout << "B";
      }
    }
    cout << '\n';
  }
  return 0;
}
