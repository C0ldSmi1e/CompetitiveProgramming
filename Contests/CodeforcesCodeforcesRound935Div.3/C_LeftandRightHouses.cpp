/**
 * Author: C0ldSmi1e
 * Created Time: 03/19/2024 07:57:12 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1945/problem/C
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
    string s;
    cin >> s;
    vector<int> r(2);
    r[0] = count(s.begin(), s.end(), '0');
    r[1] = count(s.begin(), s.end(), '1');
    vector<int> l(2);
    vector<int> idx;
      if (l[0] >= l[1] && r[1] >= r[0]) {
        idx.emplace_back(0);
      }
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        l[0] += 1;
        r[0] -= 1;
      } else {
        l[1] += 1;
        r[1] -= 1;
      }
      if (l[0] >= l[1] && r[1] >= r[0]) {
        idx.emplace_back(i + 1);
      }
    }
    double mn = n;
    int ans = 0;
    for (auto& i : idx) {
      if (mn > abs(n / 2.0 - i)) {
        mn = n / 2.0 - i;
        ans = i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
