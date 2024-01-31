/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 06:55:03
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1905/problem/C
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
    if (is_sorted(s.begin(), s.end())) {
      cout << "0\n";
      continue;
    }
    string t{s.back()};
    vector<int> idx{n - 1};
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] >= t.back()) {
        t += s[i];
        idx.emplace_back(i);
      }
    }
    reverse(t.begin(), t.end());
    for (int i = 0; i < (int) t.size(); i++) {
      s[idx[i]] = t[i];
    }
    if (is_sorted(s.begin(), s.end())) {
      cout << (int) t.size() - count(t.begin(), t.end(), t[0]) << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
