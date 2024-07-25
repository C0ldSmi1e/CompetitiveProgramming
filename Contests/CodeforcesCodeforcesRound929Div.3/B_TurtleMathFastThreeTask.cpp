/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 07:28:44 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1933/problem/B
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
    int r = 0;
    for (auto& u : a) {
      cin >> u;
      r = (r + u) % 3;
    }
    if (r == 0) {
      cout << "0\n";
      continue;
    }
    bool flag = false;
    for (auto& u : a) {
      flag |= (u % 3 == r);
    }
    if (flag) {
      cout << "1\n";
      continue;
    }
    cout << 3 - r << '\n';
  }
  return 0;
}
