/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-15 07:16:23
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START108C/problems/MD_RIEV
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
    if (n < 5) {
      cout << "0 " << n << '\n';
    } else {
      cout << "1 " << n - 1 << '\n';
    }
  }
  return 0;
}
