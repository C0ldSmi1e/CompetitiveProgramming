/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-19 06:41:24
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1914/problem/B
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k + 1);
    for (auto& u : a) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
