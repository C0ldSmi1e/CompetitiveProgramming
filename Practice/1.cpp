/**
 * Author: C0ldSmi1e
 * Created Time: 07/18/2025 11:54:48 PM
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
    set<char> S;
    for (auto& c : s) {
      S.insert(c);
    }
    cout << *S.begin() << '\n';
  }
  return 0;
}
