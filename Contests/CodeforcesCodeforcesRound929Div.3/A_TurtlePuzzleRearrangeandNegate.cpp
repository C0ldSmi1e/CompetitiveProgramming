/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 07:25:57 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1933/problem/A
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
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += abs(x);
    }
    cout << ans << '\n';
  }
  return 0;
}
