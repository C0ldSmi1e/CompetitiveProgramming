/**
 * Author: C0ldSmi1e
 * Created Time: 02/23/2025 10:31:08 AM
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
  vector<pair<int, int>> a(n);
  auto GetL = [&](string s) -> int {
    int cur = 0;
    int mn = 0;
    for (auto& c : s) {
      if (c == '(') {
        cur += 1;
      } else {
        cur -= 1;
      }
      mn = min(mn, cur);
    }
    return mn;
  };
  auto GetR = [&](string s) -> int {
    int cur = 0;
    int mn = 0;
    reverse(s.begin(), s.end());
    for (auto& c : s) {
      if (c == ')') {
        cur += 1;
      } else {
        cur -= 1;
      }
      mn = min(mn, cur);
    }
    return mn;
  };
  int ans = 0;
  int good = 0;
  map<int, int> L, R;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int l = abs(GetL(s));
    int r = abs(GetR(s));
    a[i] = make_pair(l, r);
    debug(l, r);
    if (l == 0 && r == 0) {
      good += 1;
      continue;
    }
    if (l == 0) {
      if (R[r] > 0) {
        R[r] -= 1;
        ans += 1;
      } else {
        L[r] += 1;
      }
      continue;
    }
    if (r == 0) {
      if (L[l] > 0) {
        L[l] -= 1;
        ans += 1;
      } else {
        R[l] += 1;
      }
    }
  }
  ans += good / 2;
  cout << ans << '\n';
  return 0;
}
