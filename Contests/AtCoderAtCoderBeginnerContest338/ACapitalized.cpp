/**
 * Author: C0ldSmi1e
 * Created Time: 01/30/2024 02:07:29 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc338/tasks/abc338_a
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
  bool flag = (s[0] >= 'A' && s[0] <= 'Z');
  for (int i = 1; i < (int) s.size(); i++) {
    flag &= (s[i] >= 'a' && s[i] <= 'z');
  }
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}
