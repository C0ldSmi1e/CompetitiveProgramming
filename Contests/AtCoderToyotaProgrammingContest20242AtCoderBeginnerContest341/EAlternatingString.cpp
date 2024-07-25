/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 10:37:39 PM
**/

// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc341/tasks/abc341_e
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
  string s;
  cin >> s;
  set<int> S;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      S.insert(i);
    }
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    --r;
    if (t == 1) {
      if (l - 1 >= 0) {
        if (S.count(l - 1) > 0) {
          S.erase(S.find(l - 1));
        } else {
          S.insert(l - 1);
        }
      }
      if (S.count(r) > 0) {
        S.erase(S.find(r));
      } else {
        S.insert(r);
      }
    } else {
      auto it = S.lower_bound(l);
      if (it == S.end() || *it >= r) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
