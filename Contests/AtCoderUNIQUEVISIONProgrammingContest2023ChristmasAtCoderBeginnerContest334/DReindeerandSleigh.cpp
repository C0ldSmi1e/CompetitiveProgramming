/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-26 20:35:35
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc334/tasks/abc334_d
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

  int n, q;
  cin >> n >> q;
  vector<int> r(n);
  for (auto& u : r) {
    cin >> u;
  }
  sort(r.begin(), r.end());
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + r[i];
  }
  while (q--) {
    long long x;
    cin >> x;
    int l = 0;
    int r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (x >= pref[mid]) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << r << '\n';
  }
  return 0;
}
