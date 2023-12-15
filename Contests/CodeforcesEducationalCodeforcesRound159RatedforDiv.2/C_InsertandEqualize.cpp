/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-03 06:49:47
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1902/problem/C
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
    sort(a.begin(), a.end());
    long long g = 0;
    vector<long long> d(n - 1);
    for (int i = 1; i < n; i++) {
      d[i - 1] = a[i] - a[i - 1];
      g = gcd(g, a[i] - a[i - 1]);
    }
    if (g == 0) {
      cout << "1\n";
      continue;
    }
    if (*max_element(d.begin(), d.end()) > g) {
      for (int i = n - 1; i > 0; i--) {
        if (a[i] - g != a[i - 1]) {
          a.emplace_back(a[i] - g);
          break;
        }
      }
    } else {
      if ((a.back() - a[0] - g) / g >= n) {
        a.emplace_back(a.back() + g);
      } else {
        a.emplace_back(a[0] - g);
      }
    }
    
    int mx = *max_element(a.begin(), a.end());
    long long res = 0;
    for (auto& u : a) {
      res += (mx - u) / g;
    }
    cout << res << '\n';
  }
  return 0;
}
