/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 10:00:11 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc341/tasks/abc341_b
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

  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  for (int i = 0; i < n - 1; i++) {
    long long s, t;
    cin >> s >> t;
    a[i + 1] += a[i] / s * t;
  }
  cout << a[n - 1] << '\n';
  return 0;
}
