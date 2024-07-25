/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 01:44:29 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1932/problem/C
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    string s;
    cin >> s;
    vector<int> b;
    int l = 0, r = n - 1;
    for (auto& c : s) {
      if (c == 'L') {
        b.emplace_back(a[l]);
        l += 1;
      } else {
        b.emplace_back(a[r]);
        r -= 1;
      }
    }
    reverse(b.begin(), b.end());
    vector<int> ans;
    int res = 1;
    for (auto& u : b) {
      res = res * u % m;
      ans.emplace_back(res);
    }
    reverse(ans.begin(), ans.end());
    for (auto& u : ans) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
