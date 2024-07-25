// time-limit: 2000
// problem-url: https://codeforces.com/contest/1986/problem/A
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
    vector<int> a(3);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    cout << abs(a[0] - a[1]) + abs(a[1] - a[2]) << '\n';
  }
  return 0;
}
