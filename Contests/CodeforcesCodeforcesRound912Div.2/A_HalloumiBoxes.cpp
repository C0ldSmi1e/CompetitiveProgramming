/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-30 08:37:49
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1903/problem/A
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    if (k > 1 || is_sorted(a.begin(), a.end())) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
