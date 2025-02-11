/**
 * Author: C0ldSmi1e
 * Created Time: 02/10/2025 05:22:45 PM
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
    vector<bool> st(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      int x = ((i + (a[i] % n + n) % n) % n + n) % n;
      if (st[x]) {
        flag = false;
      }
      st[x] = true;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
