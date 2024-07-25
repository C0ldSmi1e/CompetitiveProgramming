/**
 * Author: C0ldSmi1e
 * Created Time: 03/13/2024 08:00:42 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START125A/problems/BGME
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
    int odd = 0;
    int one = 0;
    for (auto& u : a) {
      cin >> u;
      if (u == 1) {
        one += 1;
      } else {
        odd ^= (u & 1);
      }
    }
    int al = ((one & 1) ? one / 2 + 1 + (1 - odd) * (n - one) : one / 2 + odd * (n - one));
    int bo = n - al;
    cout << (al == bo ? "Draw\n" : (al > bo ? "Alice\n" : "Bob\n"));
  }
  return 0;
}
