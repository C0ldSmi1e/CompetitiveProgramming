/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-23 08:22:56
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1909/problem/D
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
    long long k;
    cin >> k;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
      cout << "0\n";
      continue;
    }
    if (k >= a[0] && k <= a[n - 1]) {
      cout << "-1\n";
      continue;
    }
    long long res = 0;
    if (k > a[n - 1]) {
      long long g = k - a[n - 1];
      for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
      }
      long long y = k - g;
      for (auto& u : a) {
        res += (y - u) / g;
      }
    }
    if (k < a[0]) {
      long long g = a[0] - k;
      for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
      }
      long long y = k + g;
      for (auto& u : a) {
        res += (u - y) / g;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
