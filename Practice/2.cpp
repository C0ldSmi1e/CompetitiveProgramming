/**
 * Author: C0ldSmi1e
 * Created Time: 04/30/2025 11:25:36 PM
**/

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

  int n, s;
  cin >> n >> s;
  if ((n == 1 && s == 1) || s <= 2 * (n - 1)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n - 1; i++) {
    cout << "1 ";
  }
  cout << s - (n - 1) << '\n';
  cout << n << '\n';
  return 0;
}
