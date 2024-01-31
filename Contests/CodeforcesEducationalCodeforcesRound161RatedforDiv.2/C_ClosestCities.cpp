/**
 * Author: C0ldSmi1e
 * Created Time: 01/18/2024 07:01:06 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1922/problem/C
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
    vector<long long> pref(n);
    for (int i = 1; i < n; i++) {
      if (i == 1) {
        pref[i] = 1;
        continue;
      }
      long long dist = 1;
      if (a[i] - a[i - 1] > a[i - 1] - a[i - 2]) {
        dist = a[i] - a[i - 1];
      }
      pref[i] = pref[i - 1] + dist;
    }
    vector<long long> suff(n);
    for (int i = n - 2; i >= 0; i--) {
      if (i == n - 2) {
        suff[i] = 1;
        continue;
      }
      long long dist = 1;
      if (a[i + 1] - a[i] > a[i + 2] - a[i + 1]) {
        dist = a[i + 1] - a[i];
      }
      suff[i] = suff[i + 1] + dist;
    }
    debug(pref);
    debug(suff);
    int q;
    cin >> q;
    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      if (x < y) {
        cout << pref[y] - pref[x] << '\n';
      } else {
        cout << suff[y] - suff[x] << '\n';
      }
    }
  }
  return 0;
}
