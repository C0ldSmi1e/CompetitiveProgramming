/**
 * Author: C0ldSmi1e
 * Created Time: 06/08/2024 09:01:26 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1980/problem/B
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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int x = a[f - 1];
    sort(a.rbegin(), a.rend());
    if (k == n || a[k - 1] < x) {
      cout << "YES\n";
      continue;
    }
    if (a[k - 1] > x) {
      cout << "NO\n";
      continue;
    }
    if (a[k - 1] == a[k] && a[k] == x) {
      cout << "MAYBE\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
