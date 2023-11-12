/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-08 22:48:21
**/

// time-limit: 2000
// problem-url: 
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
    string s;
    cin >> s;
    bool flag = false;
    for (char c = '0'; c <= '1'; c++) {
      vector<int> bad(2);
      for (int i = 0; i < n; i++) {
        if (s[i] != c) {
          if (bad[(i & 1) ^ 1] > 0) {
            bad[(i & 1) ^ 1] -= 1;
          } else {
            bad[i & 1] += 1;
          }
        }
      }
      flag |= (bad[0] == 0 && bad[1] == 0);
    }
    cout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}
