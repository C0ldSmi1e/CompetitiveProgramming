/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2024 07:39:51 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1955/problem/B
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
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n * n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    vector<int> b(n * n, -1);
    b[0] = a[0];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + 1) * n + j < n * n && b[(i + 1) * n + j] == -1) {
          b[(i + 1) * n + j] = b[i * n + j] + c;
        }
        if (i * n + j + 1 < n * n && b[i * n + j + 1] == -1) {
          b[i * n + j + 1] = b[i * n + j] + d;
        }
      }
    }
    sort(b.begin(), b.end());
    cout << (a == b ? "YES\n" : "NO\n");
  }
  return 0;
}
