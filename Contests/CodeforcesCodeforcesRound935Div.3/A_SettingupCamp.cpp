/**
 * Author: C0ldSmi1e
 * Created Time: 03/19/2024 07:41:59 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1945/problem/A
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

  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a + b / 3;
    b %= 3;
    if (b > 0 && b + c < 3) {
      cout << "-1\n";
      continue;
    }
    c += b;
    ans += (c + 2) / 3;
    cout << ans << '\n';
  }
  return 0;
}
