/**
 * Author: C0ldSmi1e
 * Created Time: 02/21/2025 06:46:47 AM
**/

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
  int ans = 0;
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  vector<bool> st(n);
  auto Get = [&](vector<string> g) -> void {
    multiset<pair<int, int>> S;
    for (int i = 0; i < n; i++) {
      if (st[i]) {
        continue;
      }
      bool ok = true;
      string s = g[i];
      {
        int sum = 0;
        int mn = 0;
        for (int i = (int) s.size() - 1; i >= 0; i--) {
          if (s[i] == ')') {
            sum += 1;
          } else {
            sum -= 1;
          }
          mn = min(mn, sum);
        }
        ok &= (mn >= 0);
      }
      int sum = 0;
      int mn = 0;
      for (auto& c : s) {
        if (c == '(') {
          sum += 1;
        } else {
          sum -= 1;
        }
        mn = min(mn, sum);
      }
      auto it = S.lower_bound(make_pair(-mn, -1));
      int j = -1;
      if (ok && it != S.end() && (*it).first + sum == 0) {
        j = (*it).second;
        S.erase(it);
      }
      if (j != -1) {
        st[i] = true;
        st[j] = true;
        ans += 1;
      } else if (mn >= 0) {
        S.insert(make_pair(sum, i));
      }
    }
  };
  Get(g);
  reverse(g.begin(), g.end());
  Get(g);
  cout << ans << '\n';
  return 0;
}
