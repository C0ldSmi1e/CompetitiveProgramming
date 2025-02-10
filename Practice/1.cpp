/**
 * Author: C0ldSmi1e
 * Created Time: 02/09/2025 11:08:22 AM
**/

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
    if (n % 2 == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    set<int> S;
    for (int i = 1; i <= 2 * n; i++) {
      S.insert(i);
    }
    for (int i = 0, x = n - n / 2, y = n + 1; i < (n + 1) / 2; i++, x++, y++) {
      cout << x << ' ' << y << '\n';
    }
    for (int i = 0, x = 1, y = 2 * n - (n / 2) + 1; i < n / 2; i++, x++, y++) {
      cout << x << ' ' << y << '\n';
    }
  }
  return 0;
}
