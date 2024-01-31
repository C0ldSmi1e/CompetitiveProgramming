/**
 * Author: C0ldSmi1e
 * Created Time: 01/12/2024 02:31:49 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START116B/problems/SRTO3
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(m);
    for (auto& u : b) {
      cin >> u;
    }
    debug(a, b);
    int mx = *max_element(b.begin(), b.end());
    sort(a.begin() + n - mx, a.end());
    for (auto& u : a) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
