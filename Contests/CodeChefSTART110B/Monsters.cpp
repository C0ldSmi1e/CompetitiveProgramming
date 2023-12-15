/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-29 06:43:46
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START110B/problems/SPCP5
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

  //const int N = 1000010;
  //vector<bool> st(N);
  //for (int i = 2; i < N; i++) {
  //  for (int j = 2 * i; j < N; j += i) {
  //    st[j] = true;
  //  }
  //}
  //vector<int> primes{0};
  //for (int i = 2; i < N; i++) {
  //  if (!st[i]) {
  //    primes.emplace_back(i);
  //  }
  //}
  auto Check = [&](int x) -> bool {
    if (x == 0) {
      return true;
    }
    if (x == 1) {
      return false;
    }
    for (int i = 2; i <= x / i; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int res = (int) 1e9;
    for (int i = 0; i <= n; i = (i << 1 | 1)) {
      int x = n - i;
      if (Check(x)) {
        res = min(res, __builtin_popcount(i) + (int) (x > 0));
      }
    }
    if (res == (int) 1e9) {
      res = -1;
    }
    cout << res << '\n';
  }
  return 0;
}
