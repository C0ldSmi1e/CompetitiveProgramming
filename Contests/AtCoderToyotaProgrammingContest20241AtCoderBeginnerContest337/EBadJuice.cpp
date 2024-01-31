/**
 * Author: C0ldSmi1e
 * Created Time: 01/21/2024 10:47:31 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_e
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  int n;
  cin >> n;
  int m = 0;
  while ((1 << m) < n) {
    m += 1;
  }
  cout << m << endl;
  vector<vector<int>> a(m);
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    for (int bit = 0; bit < m; bit++) {
      if ((i >> bit) & 1) {
        a[bit].emplace_back(i);
        cnt[i] += 1;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << (int) a[i].size();
    for (auto& u : a[i]) {
      cout << ' ' << u + 1;
    }
    cout << endl;
  }
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  assert((int) s.size() == m);
  int res = 0;
  for (auto& c : s) {
    res = res * 2 + (int) (c == '1');
  }
  cout << res + 1 << endl;
  return 0;
}
