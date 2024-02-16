/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 06:48:11 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START121A/problems/XOR1248
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
    vector<long long> a(n);
    long long sum = 0;
    for (auto& u : a) {
      cin >> u;
      sum ^= u;
    }
    long long ans = sum;
    for (auto& u : a) {
      long long s = (sum ^ u);
      long long cnt = 0;
      for (int bit = 60; bit >= 0; bit--) {
        cnt <<= 1ll;
        cnt += ((u >> bit) & 1ll);
        if (((s >> bit) & 1ll) == 0 && cnt > 0) {
          cnt -= 1;
          s |= (1ll << bit);
        }
      }
      if (cnt > 0) {
        cnt &= 1ll;
        s ^= cnt;
      }
      ans = max(ans, s);
    }
    cout << ans << '\n';
  }
  return 0;
}
