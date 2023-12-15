/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-20 22:25:41
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1898/problem/D
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
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      tot += abs(a[i] - b[i]);
    }
    long long res = tot;
    int mx_a = *max_element(a.begin(), a.end());
    int mn_b = *min_element(b.begin(), b.end());
    res += 2ll * max(0, mx_a - mn_b);
    cout << res << '\n';
  }
  return 0;
}
