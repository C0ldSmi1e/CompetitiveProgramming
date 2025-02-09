// time-limit: 1000
// problem-url: https://codeforces.com/contest/2009/problem/B
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
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    for (int i = n - 1; i >= 0; i--) {
      int j = g[i].find('#');
      cout << j + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
