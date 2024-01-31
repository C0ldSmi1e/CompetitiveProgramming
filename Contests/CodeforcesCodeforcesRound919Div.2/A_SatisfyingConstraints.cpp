// time-limit: 1000
// problem-url: https://codeforces.com/contest/1920/problem/A
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
    const int INF = (int) 2e9;
    int l = -INF;
    int r = INF;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int t, x;
      cin >> t >> x;
      if (t == 1) {
        l = max(l, x);
      }
      if (t == 3) {
        a.emplace_back(x);
      }
      if (t == 2) {
        r = min(r, x);
      }
    }
    int res = max(0, r - l + 1);
    for (auto& u : a) {
      if (u >= l && u <= r) {
        res -= 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
