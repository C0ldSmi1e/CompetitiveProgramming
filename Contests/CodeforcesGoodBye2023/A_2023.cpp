/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-30 06:51:13
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1916/problem/A
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
    int m = 2023;
    bool flag = true;
    for (auto& u : a) {
      cin >> u;
      flag &= (m % u == 0);
      m /= u;
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < k - 1; i++) {
      cout << "1 ";
    }
    cout << m << '\n';
  }
  return 0;
}
