/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 06:36:51
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1899/problem/A
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (n % 3 == 0 ? "Second\n" : "First\n");
  }
  return 0;
}
