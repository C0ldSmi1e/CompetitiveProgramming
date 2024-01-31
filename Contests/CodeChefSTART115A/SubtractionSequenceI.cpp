/**
 * Author: C0ldSmi1e
 * Created Time: 01/04/2024 11:58:26 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START115A/problems/SUBSEQI
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    auto Get = [&]() -> long long {
      long long ans = sum;
      set<int> S{a.back()};
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] < *S.begin()) {
          ans -= a[i];
          int x = *S.begin();
          S.erase(S.begin());
          S.insert(a[i]);
          S.insert(x - a[i]);
        } else {
          ans -= *S.begin();
          break;
        }
      }
      return ans;
    };
    cout << Get() << '\n';
    while (q--) {
      int i, x;
      cin >> i >> x;
      --i;
      sum -= a[i];
      a[i] = x;
      sum += a[i];
      cout << Get() << '\n';
    }
  }
  return 0;
}
