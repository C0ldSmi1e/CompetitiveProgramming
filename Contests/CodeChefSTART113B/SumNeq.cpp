/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-20 06:32:40
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START113B/problems/SUMNEQ7
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
    for (auto& u : a) {
      cin >> u;
    }
    if (n == 4) {
      cout << ((a[0] + a[1] != a[2] + a[3]) ? "YES\n" : "NO\n");
      continue;
    }
    cout << (count(a.begin(), a.end(), a[0]) != n ? "YES\n" : "NO\n");
  }
  return 0;
}
