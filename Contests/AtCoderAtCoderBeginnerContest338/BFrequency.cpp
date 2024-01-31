/**
 * Author: C0ldSmi1e
 * Created Time: 01/30/2024 02:19:18 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc338/tasks/abc338_b
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

  string s;
  cin >> s;
  vector<int> cnt(26);
  int mx = 0;
  char res;
  for (int i = (int) s.size() - 1; i >= 0; i--) {
    cnt[(int) s[i] - 'a'] += 1;
    if (cnt[(int) (s[i] - 'a')] > mx) {
      res = s[i];
      mx = cnt[(int) (s[i] - 'a')];
    } else if (cnt[(int) (s[i] - 'a')] == mx) {
      res = min(res, s[i]);
    }
  }
  cout << res << '\n';
  return 0;
}
