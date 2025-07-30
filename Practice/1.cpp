/**
 * Author: C0ldSmi1e
 * Created Time: 07/30/2025 09:53:37 AM
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

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int ones = count(s.begin(), s.end(), '1');
    cout << ones << '\n';
  }
  return 0;
}
