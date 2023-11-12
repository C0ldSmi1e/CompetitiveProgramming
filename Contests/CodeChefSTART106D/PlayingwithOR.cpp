/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 07:49:45
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2304
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> cnt(30);
    int tot = 0;
    int res = 0;
    auto Add = [&](int x) -> void {
      if (cnt[x] == 0) {
        tot += 1;
      }
      cnt[x] += 1;
    };
    auto Del = [&](int x) -> void {
      if (cnt[x] == 1) {
        tot -= 1;
      }
      cnt[x] -= 1;
    };
    for (int i = 0; i < k - 1; i++) {
      for (int bit = 0; bit < 30; bit++) {
        if ((a[i] >> bit) & 1) {
          Add(bit);
        }
      }
    }
    for (int i = k - 1; i < n; i++) {
      for (int bit = 0; bit < 30; bit++) {
        if ((a[i] >> bit) & 1) {
          Add(bit);
        }
      }
      debug(a[i], cnt);
      res += (cnt[0] > 0);
      for (int bit = 0; bit < 30; bit++) {
        if ((a[i - k + 1] >> bit) & 1) {
          Del(bit);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
