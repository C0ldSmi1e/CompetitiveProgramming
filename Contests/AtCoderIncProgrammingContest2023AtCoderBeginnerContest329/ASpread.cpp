/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-18 22:25:29
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc329/tasks/abc329_a
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
  for (auto& c : s) {
    cout << c << ' ';
  }
  return 0;
}
