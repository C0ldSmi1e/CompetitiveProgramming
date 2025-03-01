/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2025 10:44:34 PM
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
    int n = 4;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
      u %= 12;
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    if (abs(order[0] - order[2]) == 1 && !((order[0] == 1 && order[2] == 2) || (order[0] == 2 && order[2] == 1))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
