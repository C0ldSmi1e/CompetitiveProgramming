/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-17 09:01:38
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START112B/problems/PERMUTATION_
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
    int n, x;
    cin >> n >> x;
    int t = x;
    if (n % 2 == 1 && x == n / 2 + 1) {
      cout << "-1\n";
      continue;
    }
    vector<int> res(n);
    int y = n - x + 1;
    int tx = x;
    int ty = y;
    int i = 0, j = n - 1;
    if (2 * x > n) {
      swap(x, y);
      swap(tx, ty);
    }
    while (x >= 1 && y <= n) {
      res[i] = x;
      res[j] = y;
      x -= 1;
      y += 1;
      i += 1;
      j -= 1;
    }
    x = tx + 1;
    y = ty - 1;
    while (x <= y) {
      res[i] = x;
      res[j] = y;
      x += 1;
      y -= 1;
      i += 1;
      j -= 1;
    }
    if (res[0] != t) {
      reverse(res.begin(), res.end());
    }
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}

/*
 * 1 2 3
 * 3 4 2 1
 * x ... 1 x+1 ... mid-1, mid, mid+1, y-1, n ... y
 */
