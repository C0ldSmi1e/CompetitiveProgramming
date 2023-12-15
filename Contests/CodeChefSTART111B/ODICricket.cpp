/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-07 21:34:43
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START111B/problems/BATGRIP
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
    vector<int> a(n - 1);
    int x = n;
    for (int i = 0; i < n - 1; i++) {
      cin >> a[i];
      x += i + 1;
      x -= a[i];
    }
    vector<int> b(n);
    for (int i = n - 1; i > 0; i--) {
      int y = a[i - 1];
      b[i] = min(x, y);
      x = max(x, y);
    }
    b[0] = x;
    long long res = 0;
    for (int i = 0; i < n; i++) {
      res += max(i + 1, b[i]);
    }
    cout << res << '\n';
  }
  return 0;
}
