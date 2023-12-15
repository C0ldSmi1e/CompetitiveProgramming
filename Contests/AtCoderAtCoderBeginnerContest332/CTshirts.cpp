/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-11 14:47:44
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc332/tasks/abc332_c
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

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = '0' + s;
  n += 1;
  int res = 0;
  for (int i = n - 1, one = 0, two = 0; i >= 0; i--) {
    if (s[i] == '0') {
      res = max(res, two + max(0, one - m));
      one = two = 0;
    }
    one += (int) (s[i] == '1');
    two += (int) (s[i] == '2');
  }
  cout << res << '\n';
  return 0;
}
