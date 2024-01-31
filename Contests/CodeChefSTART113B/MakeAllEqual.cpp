/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-20 23:23:16
**/

// time-limit: 2000
// problem-url: 
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int mx = *max_element(a.begin(), a.end());
    for (auto& u : a) {
      u = mx - u;
    }
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    mx = *max_element(a.begin(), a.end());
    if (1ll * mx * (m - 1) >= sum - mx) {
      cout << mx << '\n';
    } else {
      cout << (sum + m - 1) / m << '\n';
    }
  }
  return 0;
}
