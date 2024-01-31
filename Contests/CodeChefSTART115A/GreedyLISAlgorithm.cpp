/**
 * Author: C0ldSmi1e
 * Created Time: 01/03/2024 06:33:37 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START115A/problems/GREEDYLIS
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
    if (k == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << " \n"[i == n];
      }
      continue;
    }
    if (k >= n - 1) {
      cout << "-1\n";
      continue;
    }
    int n1 = n / 2;
    int n2 = n - n1;
    if (n % 2 == k % 2) {
      n1 -= k / 2;
      n2 += k / 2;
    } else {
      if (n & 1) {
        n1 -= k / 2;
        n2 += k / 2;
        n2 -= 1;
      } else {
        n1 -= k / 2;
        n2 += k / 2;
        n1 -= 1;
      }
    }
    for (int i = n - n1 + 1; i <= n; i++) {
      cout << i << ' ';
    }
    if (n1 + n2 != n) {
      cout << n - n1 << ' ';
    }
    for (int i = 1; i <= n2; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}
