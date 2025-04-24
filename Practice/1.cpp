/**
 * Author: C0ldSmi1e
 * Created Time: 04/23/2025 08:37:47 AM
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
    if (n & 1) {
      for (int i = 0; i < n; i += 2) {
        cout << i + 1 << ' ';
      }
      for (int i = 1; i < n; i += 2) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
      continue;
    }
    cout << "-1\n";
  }
  return 0;
}
