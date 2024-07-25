/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 11:51:03 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1932/problem/B
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
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    for (int i = 1; i < n; i++) {
      if (a[i] <= a[i - 1]) {
        a[i] = (a[i - 1] / a[i] + 1) * a[i];
      }
    }
    cout << a.back() << '\n';
  }
  return 0;
}
