/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2024 07:55:06 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1955/problem/C
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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    if (k >= accumulate(a.begin(), a.end(), 0ll)) {
      cout << n << '\n';
      continue;
    }
    int ans = 0;
    long long l = (k + 1) / 2;
    long long r = k / 2;
    for (int i = 0; i < n; i++) {
      if (l >= a[i]) {
        l -= a[i];
        ans += 1;
        continue;
      }
      break;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (r >= a[i]) {
        r -= a[i];
        ans += 1;
        continue;
      }
      break;
    }
    cout << ans << '\n';
  }
  return 0;
}
