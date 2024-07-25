/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 11:25:57 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_c
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

  int n, k;
  cin >> n >> k;
  long long ans = (1ll + k) * k / 2ll;
  set<int> S;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= k && S.count(x) == 0) {
      ans -= x;
      S.insert(x);
    }
  }
  cout << ans << '\n';
  return 0;
}
