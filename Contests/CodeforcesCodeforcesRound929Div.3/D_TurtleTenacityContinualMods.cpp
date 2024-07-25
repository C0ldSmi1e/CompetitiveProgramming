/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 07:38:34 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1933/problem/D
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
    sort(a.begin(), a.end());
    int cnt = count(a.begin(), a.end(), a[0]);
    if (cnt == 1) {
      cout << "YES\n";
      continue;
    }
    bool flag = false;
    for (auto& u : a) {
      flag |= u % a[0] != 0;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
