/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 06:44:20
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1900/problem/B
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

  auto Check = [&](int a, int b, int c) -> int {
    int take = min(b, c);
    b -= take;
    c -= take;
    if (max(b, c) & 1) {
      return 0;
    }
    return (int) (a > 0);
  };
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << Check(a, b, c) << ' ' << Check(b, a, c) << ' ' << Check(c, a, b) << '\n';
  }
  return 0;
}
