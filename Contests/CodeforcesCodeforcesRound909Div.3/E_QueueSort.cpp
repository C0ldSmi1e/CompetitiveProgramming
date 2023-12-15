/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 07:24:05
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1899/problem/E
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
    int mn = *min_element(a.begin(), a.end());
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == mn) {
        p = i;
        break;
      }
    }
    if (is_sorted(a.begin() + p, a.end())) {
      cout << p << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
