/**
 * Author: C0ldSmi1e
 * Created Time: 03/13/2024 07:33:54 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START125A/problems/BILM
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
    string s;
    cin >> s;
    int c1 = count(s.begin(), s.end(), '1');
    if (k <= c1 - 1) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '1' && k > 0) {
          s[i] = '0';
          k -= 1;
        }
      }
      cout << s << '\n';
      continue;
    }
    cout << string(n - k, '0') << '\n';
  }
  return 0;
}
