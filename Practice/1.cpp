/**
 * Author: C0ldSmi1e
 * Created Time: 02/11/2025 11:07:09 PM
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
    s.pop_back();
    s.pop_back();
    s += "i";
    cout << s << '\n';
  }
  return 0;
}
