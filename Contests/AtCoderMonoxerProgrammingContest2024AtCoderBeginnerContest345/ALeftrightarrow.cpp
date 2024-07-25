/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 09:43:37 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc345/tasks/abc345_a
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
  bool flag = s[0] == '<';
  flag &= s.back() == '>';
  flag &= count(s.begin(), s.end(), '=') == (int) (s.size() - 2);
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}
