/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 15:47:05
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc333/tasks/abc333_b
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

  auto Get = [&](string s) -> int {
    int x = (int) (s[0] - 'A');
    int y = (int) (s[1] - 'A');
    return min(abs(x - y), (5 - abs(x - y)) % 5);
  };
  string s;
  cin >> s;
  string t;
  cin >> t;
  int ds = Get(s);
  int dt = Get(t);
  debug(ds, dt);
  cout << (ds == dt ? "Yes\n" : "No\n");
  return 0;
}
