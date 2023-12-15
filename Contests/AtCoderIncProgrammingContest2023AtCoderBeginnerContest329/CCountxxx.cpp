/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-18 22:32:20
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc329/tasks/abc329_c
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
  map<char, int> mp;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && s[i] == s[j]) {
      j += 1;
    }
    mp[s[i]] = max(mp[s[i]], j - i);
    i = j - 1;
  }
  long long res = 0;
  for (auto& [c, mx] : mp) {
    res += mx;
  }
  cout << res << '\n';
  return 0;
}
