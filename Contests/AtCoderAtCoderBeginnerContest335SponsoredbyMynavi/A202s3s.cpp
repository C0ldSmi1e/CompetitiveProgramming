/**
 * Author: C0ldSmi1e
 * Created Time: 01/07/2024 11:25:40 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc335/tasks/abc335_a
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
  s.back() = '4';
  cout << s << '\n';
  return 0;
}
