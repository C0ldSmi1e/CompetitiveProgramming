/**
 * Author: C0ldSmi1e
 * Created Time: 07/09/2025 10:20:16 PM
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    if (is_sorted(a.begin(), a.end())) {
      cout << "NO\n";
      continue;
    }
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n && x == -1; j++) {
        if (a[i] > a[j]) {
          x = a[i];
          y = a[j];
        }
      }
    }
    cout << "YES\n";
    cout << "2\n";
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
