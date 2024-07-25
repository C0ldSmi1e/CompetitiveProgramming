/**
 * Author: C0ldSmi1e
 * Created Time: 05/02/2024 09:38:44 PM
**/

// time-limit: 5000
// problem-url: https://codeforces.com/contest/1968/problem/F
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> pref(n + 1);
    map<int, vector<int>> pos;
    pos[0].emplace_back(0);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] ^ a[i];
      pos[pref[i + 1]].emplace_back(i + 1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l;
      if (pref[r] == pref[l]) {
        cout << "YES\n";
        continue;
      }
      int L = *upper_bound(pos[pref[r]].begin(), pos[pref[r]].end(), l);
      int R = *prev(lower_bound(pos[pref[l]].begin(), pos[pref[l]].end(), r));
      if (L < R) {
        cout << "YES\n";
        continue;
      }
      cout << "NO\n";
    }
    cout << '\n';
  }
  return 0;
}
