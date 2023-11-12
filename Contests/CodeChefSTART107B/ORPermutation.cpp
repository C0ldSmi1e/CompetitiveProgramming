/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-08 06:45:03
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START107B/problems/PERMOR
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a;
    int r = n % 4;
    n = n / 4 * 4;
    if (r == 1) {
      a.emplace_back(n + 1);
    }
    if (r == 2) {
      a.emplace_back(n + 1);
      a.emplace_back(n + 2);
    }
    if (r == 3) {
      a.emplace_back(n + 1);
      a.emplace_back(n + 3);
      a.emplace_back(n + 2);
    }
    for (int i = 0; i < n; i += 4) {
      vector<int> b;
      for (int j = 0; j < 4 && i + j < n; j++) {
        b.emplace_back(i + j + 1);
      }
      int m = (int) b.size();
      vector<bool> st(m);
      if ((int) a.size() == 1) {
        st[0] = true;
        a.emplace_back(b[0]);
      } else if ((int) a.size() == 0) {
        st[0] = st[1] = true;
        a.emplace_back(b[0]);
        a.emplace_back(b[1]);
      }
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (st[l]) {
            continue;
          }
          int x = a[(int) a.size() - 2] % 4;
          int y = a.back() % 4;
          int z = b[l] % 4;
          if (z != (x | y)) {
            a.emplace_back(b[l]);
            st[l] = true;
          }
        }
      }
    }
    for (auto& u : a) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
