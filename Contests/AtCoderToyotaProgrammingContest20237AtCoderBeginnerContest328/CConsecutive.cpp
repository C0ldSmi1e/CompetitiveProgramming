/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 11:40:13
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_c
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> good(n);
  for (int i = 0; i < n - 1; i++) {
    good[i] = (int) (s[i] == s[i + 1]);
  }
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + good[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int res = pref[r] - pref[l - 1];
    if (good[r - 1]) {
      res -= 1;
    }
    cout << res << '\n';
  }
  return 0;
}
