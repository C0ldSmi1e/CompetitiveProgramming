/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-06 06:49:20
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START111B/problems/FIX
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
    int mx = *max_element(a.begin(), a.end());
    set<int> S;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      if (S.count(a[i]) > 0) {
        b[i] = mx;
      } else {
        b[i] = a[i];
        S.insert(a[i]);
      }
    }
    for (auto& u : b) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
