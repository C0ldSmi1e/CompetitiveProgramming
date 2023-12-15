/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-24 06:57:01
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1901/problem/C
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
    int mn = *min_element(a.begin(), a.end());
    vector<int> op;
    while (mx != mn) {
      if (mn & 1) {
        op.emplace_back(1);
        mn = (mn + 1) / 2;
        mx = (mx + 1) / 2;
      } else {
        op.emplace_back(0);
        mn /= 2;
        mx /= 2;
      }
    }
    cout << (int) op.size() << '\n';
    if ((int) op.size() <= n) {
      for (int i = 0; i < (int) op.size(); i++) {
        cout << op[i] << " \n"[i == (int) op.size() - 1];
      }
    }
  }
  return 0;
}
