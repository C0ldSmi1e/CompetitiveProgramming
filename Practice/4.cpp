/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2025 08:10:33 AM
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
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}
