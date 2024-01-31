/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-17 08:53:03
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START112B/problems/CURSED
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
    sort(a.begin(), a.end());
    long long pref = 0;
    int cnt = n - 1;
    vector<bool> st(n);
    vector<int> res{a[0]};
    pref += a[0];
    for (int i = 1; i < n; i++) {
      if (pref < a[i]) {
        cnt -= 1;
        pref += a[i];
        res.emplace_back(a[i]);
      } else {
        st[i] = true;
      }
    }
    for (int i = 0; i < n ;i++) {
      if (st[i]) {
        res.emplace_back(a[i]);
      }
    }
    cout << cnt << '\n';
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
