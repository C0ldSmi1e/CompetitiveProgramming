/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-04 05:04:33
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc327/tasks/abc327_b
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

  long long x;
  cin >> x;
  if (x == 1) {
    cout << "1\n";
    return 0;
  }
  for (int i = 2; i <= 20; i++) {
    int cnt = 0;
    long long tx = x;
    if (x % i == 0) {
      while (x % i == 0) {
        cnt += 1;
        x /= i;
      }
      if (cnt == i && x == 1) {
        cout << cnt << '\n';
        return 0;
      }
      x = tx;
    }
  }
  cout << "-1\n";
  return 0;
}
