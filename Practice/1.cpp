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
    int n = (int) s.size();
    int ans = (int) s.size();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        ans = 1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
