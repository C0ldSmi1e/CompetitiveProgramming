/**
 * Author: C0ldSmi1e
 * Created Time: 02/02/2024 10:33:32 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1918/problem/B
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
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    for (int i = 1; i <= n; i++) {
      cout << i << " \n"[i == n];
    }
    for (auto& i : order) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}

/*
3
5
1 2 3 4 5
5 4 3 2 1
3
3 1 2
3 1 2
6
2 5 6 1 3 4
1 5 3 6 2 4

1 2 3 4 5 6
6 1 2 4 5 3
*/
