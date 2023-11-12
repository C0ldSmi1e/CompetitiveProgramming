/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 07:43:00
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ23_2
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
    int n, x, d;
    cin >> n >> x >> d;
    cout << d + n / (5 * x) << '\n';
  }
  return 0;
}
