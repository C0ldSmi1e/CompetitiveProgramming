/**
 * Author: C0ldSmi1e
 * Created Time: 06/10/2024 04:00:41 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1984/problem/C1
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
    vector<long long> b;
    b.emplace_back(a[0]);
    if (a[0] < 0) {
      b.emplace_back(-a[0]);
    }
    for (int i = 1; i < n; i++) {
      sort(b.begin(), b.end());
      vector<long long> nb;
      nb.emplace_back(b[0] + a[i]);
      if (b[0] < 0) {
        nb.emplace_back(-b[0] + a[i]);
      }
      nb.emplace_back(b.back() + a[i]);
      if (b.back() < 0) {
        nb.emplace_back(-b.back() + a[i]);
      }
      swap(b, nb);
    }
    long long ans = 0;
    for (auto& u : b) {
      ans = max(ans, abs(u));
    }
    cout << ans << '\n';
  }
  return 0;
}

