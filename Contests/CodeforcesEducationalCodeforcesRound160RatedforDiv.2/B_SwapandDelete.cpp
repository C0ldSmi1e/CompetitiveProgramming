/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-18 06:44:47
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1913/problem/B
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
    int c0 = count(s.begin(), s.end(), '0');
    int c1 = count(s.begin(), s.end(), '1');
    int n = (int) s.size();
    int res = n;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
      cnt[(int) (s[i] - '0')] += 1;
      if (c0 >= cnt[1] && c1 >= cnt[0]) {
        res = min(res, c0 - cnt[1] + c1 - cnt[0]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
