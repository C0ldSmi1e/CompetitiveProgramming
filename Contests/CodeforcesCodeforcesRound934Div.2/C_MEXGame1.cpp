/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 07:52:03 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1944/problem/C
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
    vector<int> cnt(n);
    for (auto& u : a) {
      cin >> u;
      cnt[u] += 1;
    }
    int ans = -1;
    bool one = false;
    for (int i = 0; i < n; i++) {
      if (cnt[i] == 1) {
        if (one) {
          ans = i;
          break;
        }
        one = true;
      }
      if (cnt[i] == 0) {
        ans = i;
        break;
      }
    }
    if (ans == -1) {
      ans = n;
    }
    cout << ans << '\n';
  }
  return 0;
}
