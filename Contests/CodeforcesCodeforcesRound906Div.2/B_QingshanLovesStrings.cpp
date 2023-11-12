/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-28 07:42:31
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1890/problem/B
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
      flag &= (s[i] != s[i + 1]);
    }
    if (flag) {
      cout << "YES\n";
      continue;
    }
    flag = true;
    for (int i = 0; i < m - 1; i++) {
      flag &= (t[i] != t[i + 1]);
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    if (t[0] != t.back()) {
      cout << "NO\n";
      continue;
    }
    flag = true;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        flag &= (s[i] != t[0]);
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}

