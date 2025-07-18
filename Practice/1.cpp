/**
 * Author: C0ldSmi1e
 * Created Time: 07/17/2025 11:42:52 PM
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
    int a, b;
    cin >> a >> b;
    if (a * 2 < b) {
      cout << "0\n";
      continue;
    }
    int l = 0, r = a;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a - mid < b - 2 * mid) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    cout << a - r << '\n';
  }
  return 0;
}
