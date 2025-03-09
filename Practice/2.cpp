/**
 * Author: C0ldSmi1e
 * Created Time: 03/09/2025 08:53:41 AM
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    string sn = to_string(n);
    int len = (int) sn.size();
    for (int a = 1; a <= 10000; a++) {
      int tot = a * len;
      int mx_b = tot - 1;
      int mn_b = tot - 7;
      string s;
      while ((int) s.size() <= 9) {
        s += sn;
      }
      for (int b = mn_b; b <= mx_b; b++) {
        if (b >= 1 && b <= 10000) {
          int c = tot - b;
          string t = s.substr(0, c);
          if (stoi(t) == a * n - b) {
            ans.emplace_back(a, b);
          }
        }
      }
    }
    cout << (int) ans.size() << '\n';
    for (auto& [a, b] : ans) {
      cout << a << ' ' << b << '\n';
    }
  }
  return 0;
}
