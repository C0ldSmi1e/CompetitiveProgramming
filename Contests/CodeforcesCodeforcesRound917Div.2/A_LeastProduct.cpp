/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-24 06:37:41
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1917/problem/A
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
    int cnt = 0;
    int zero = 0;
    for (auto& u : a) {
      cin >> u;
      cnt += (int) (u < 0);
      zero += (int) (u == 0);
    }
    debug(cnt);
    if (zero > 0) {
      cout << "0\n";
      continue;
    }
    if (cnt & 1) {
      cout << "0\n";
      continue;
    }
    cout << "1\n";
    cout << "1 0\n";
  }
  return 0;
}
