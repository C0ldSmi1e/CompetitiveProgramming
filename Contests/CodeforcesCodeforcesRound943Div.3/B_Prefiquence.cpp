/**
 * Author: C0ldSmi1e
 * Created Time: 05/02/2024 07:49:32 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1968/problem/B
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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    while (j < m) {
      if (b[j] == a[i]) {
        i += 1;
        j += 1;
        continue;
      }
      j += 1;
    }
    cout << i << '\n';
  }
  return 0;
}
