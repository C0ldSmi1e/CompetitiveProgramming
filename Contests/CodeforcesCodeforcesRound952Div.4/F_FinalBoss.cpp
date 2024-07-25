/**
 * Author: C0ldSmi1e
 * Created Time: 06/11/2024 08:49:04 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1985/problem/F
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
    long long h;
    int n;
    cin >> h >> n;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<long long> c(n);
    for (auto& u : c) {
      cin >> u;
    }
    long long l = 0, r = (long long) 1e13;
    auto Check = [&](long long cnt) -> bool {
      long long m = 0;
      for (int i = 0; i < n; i++) {
        m += a[i] * ((cnt + c[i] - 1) / c[i]);
        if (m >= h) {
          return true;
        }
      }
      return m >= h;
    };
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (Check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << '\n';
  }
  return 0;
}
