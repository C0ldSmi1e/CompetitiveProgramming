/**
 * Author: C0ldSmi1e
 * Created Time: 03/01/2024 06:39:14 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1934/problem/A
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
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int l = i + 3; l < n; l++) {
        int j = l - 1;
        int k = i + 1;
        ans = max(ans, abs(a[i] - a[j]) + abs(a[j] - a[k]) + abs(a[l] - a[k]) + abs(a[l] - a[i]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
