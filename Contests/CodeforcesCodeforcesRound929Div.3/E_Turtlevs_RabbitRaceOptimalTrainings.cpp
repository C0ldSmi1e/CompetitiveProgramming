/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 07:47:53 AM
**/

// time-limit: 5000
// problem-url: https://codeforces.com/contest/1933/problem/E
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
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    int q;
    cin >> q;
    while (q--) {
      int L, u;
      cin >> L >> u;
      int l = L, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (pref[mid] - pref[L - 1] <= u) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      auto Get = [&](int x) -> long long {
        long long sum = (pref[x] - pref[L - 1]) * u;
        long long ap = (pref[x] - pref[L - 1] - 1) * (pref[x] - pref[L - 1]) / 2;
        return sum - ap;
      };
      int ans = (r == n || (Get(r) >= Get(r + 1)) ? r : r + 1);
      cout << ans << ' ';
    }
    cout << '\n';
  }
  return 0;
}
