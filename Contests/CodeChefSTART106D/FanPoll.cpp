/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 07:38:45
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2301
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

  int a, b, c;
  cin >> a >> b >> c;
  cout << (a > b && a > c ? "Yes\n" : "No\n");
  return 0;
}
