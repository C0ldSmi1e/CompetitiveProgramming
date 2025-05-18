/**
 * Author: C0ldSmi1e
 * Created Time: 05/15/2025 10:52:04 PM
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
    if (n < 5) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= n; i += 2) {
      if (i == 5) {
        continue;
      }
      cout << i << ' ';
    }
    cout << "5 4 ";
    for (int i = 2; i <= n; i += 2) {
      if (i == 4) {
        continue;
      }
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}
