/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-27 07:42:57
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START114A/problems/AGAME
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
    long long odd = 0;
    long long even = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i & 1) {
        odd += a[i];
      } else {
        even += a[i];
      }
    }
    if (n == 1) {
      if (a[0] > 1) {
        cout << "Alice\n";
      } else {
        cout << "Bob\n";
      }
      continue;
    }
    if ((even + odd) & 1) {
      cout << "Bob\n";
      continue;
    }
    if (even & 1) {
      if (((even + odd) / 2) & 1) {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    } else {
      if (((even + odd) / 2) & 1) {
        cout << "Alice\n";
      } else {
        cout << "Bob\n";
      }
    }
  }
  return 0;
}
