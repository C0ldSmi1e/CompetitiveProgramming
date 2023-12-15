/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-25 06:50:23
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1896/problem/A
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
    while (true) {
      bool flag = true;
      for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          flag = false;
        }
      }
      if (flag) {
        break;
      }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
  }
  return 0;
}
