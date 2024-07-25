/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 07:32:43 AM
**/

// time-limit: 5000
// problem-url: https://codeforces.com/contest/1933/problem/C
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
    long long a, b, l;
    cin >> a >> b >> l;
    set<long long> S;
    for (int i = 0; (long long) pow(a, i) <= l; i++) {
      long long pa = (long long) pow(a, i);
      for (int j = 0; pa * (long long) pow(b, j) <= l; j++) {
        long long pb = (long long) pow(b, j);
        if (l % (pa * pb) == 0) {
          S.insert(l / (pa * pb));
        }
      }
    }
    cout << (int) S.size() << '\n';
  }
  return 0;
}
