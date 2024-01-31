/**
 * Author: C0ldSmi1e
 * Created Time: 01/27/2024 07:04:27 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1925/problem/C
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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<int> cnt(k);
    int cur_n = 0;
    int cur_k = 0;
    string res;
    for (int i = 0; i < m; i++) {
      cnt[(int) (s[i] - 'a')] += 1;
      if (cnt[(int) (s[i] - 'a')] == 1) {
        cur_k += 1;
      }
      if (cur_k == k) {
        res += s[i];
        cur_n += 1;
        cur_k = 0;
        cnt = vector<int>(k, 0);
      }
    }
    if (cur_n >= n) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
    for (int i = 0; i < k; i++) {
      if (cnt[i] == 0) {
        res += string(n - (int) res.size(), (char) (i + 'a'));
        break;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
