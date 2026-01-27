/**
 * Author: C0ldSmi1e
 * Created Time: 01/26/2026 09:29:41 PM
**/

// time-limit: 1500
// problem-url: https://codeforces.com/contest/2185/problem/B
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
    int mx = *max_element(a.begin(), a.end());
    cout << mx * n << '\n';
  }
  return 0;
}
