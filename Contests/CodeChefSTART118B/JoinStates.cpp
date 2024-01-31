/**
 * Author: C0ldSmi1e
 * Created Time: 01/24/2024 06:35:35 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START118B/problems/JOINSTATE
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      int j = i;
      while (j < n && sum < m) {
        sum += a[j];
        j += 1;
      }
      if (sum >= m) {
        ans += 1;
      }
      i = j - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
