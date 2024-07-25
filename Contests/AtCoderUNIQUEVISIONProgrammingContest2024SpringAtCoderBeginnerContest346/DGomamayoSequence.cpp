/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 01:35:12 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_d
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
  string s;
  cin >> s;
  vector<int> c(n);
  for (auto& u : c) {
    cin >> u;
  }
  vector<vector<long long>> pref(n + 1, vector<long long>(2));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 1; j++) {
      pref[i + 1][j] = pref[i][j ^ 1] + ((char) (j + '0') == s[i] ? 0 : c[i]);
    }
  }
  vector<vector<long long>> suff(n + 1, vector<long long>(2));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= 1; j++) {
      suff[i][j] = suff[i + 1][j ^ 1] + ((char) (j + '0') == s[i] ? 0 : c[i]);
    }
  }
  debug(pref);
  debug(suff);
  const long long INF = (long long) 1e18;
  long long ans = INF;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= 1; j++) {
      // [i, i+1] is j
      long long tot = 0;
      tot += (s[i] == (char) (j + '0') ? 0 : c[i]);
      tot += (s[i + 1] == (char) (j + '0') ? 0 : c[i + 1]);
      tot += pref[i][j ^ 1];
      tot += suff[i + 2][j ^ 1];
      ans = min(ans, tot);
    }
  }
  cout << ans << '\n';
  return 0;
}
