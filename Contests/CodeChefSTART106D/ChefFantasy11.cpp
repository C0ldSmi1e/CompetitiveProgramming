/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 07:45:10
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2303
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
    int n;
    cin >> n;
    cout << n * (n - 1) << '\n';
  }
  return 0;
}
