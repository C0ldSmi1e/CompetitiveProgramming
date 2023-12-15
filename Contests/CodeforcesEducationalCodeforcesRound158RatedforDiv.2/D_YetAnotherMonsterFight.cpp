/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-24 07:33:57
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1901/problem/D
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
  vector<long long> pref(n);
  for (int i = 0; i < n; i++) {
    pref[i] = a[i] + n - i - 1;
    if (i > 0) {
      pref[i] = max(pref[i], pref[i - 1]);
    }
  }
  vector<long long> suff(n);
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = a[i] + i;
    if (i + 1 < n) {
      suff[i] = max(suff[i], suff[i + 1]);
    }
  }
  long long res = (long long) 1e18;
  for (int i = 0; i < n; i++) {
    long long ans = a[i];
    if (i > 0) {
      ans = max(ans, pref[i - 1]);
    }
    if (i + 1 < n) {
      ans = max(ans, suff[i + 1]);
    }
    res = min(res, ans);
  }
  cout << res << '\n';
  return 0;
}
