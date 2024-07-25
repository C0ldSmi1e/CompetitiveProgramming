/**
 * Author: C0ldSmi1e
 * Created Time: 06/08/2024 08:55:43 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1980/problem/A
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
    string s;
    cin >> s;
    vector<int> cnt(7);
    for (auto& c : s) {
      cnt[(int) (c - 'A')] += 1;
    }
    debug(cnt);
    int ans = 0;
    for (int i = 0; i < 7; i++) {
      ans += max(0, m - cnt[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
