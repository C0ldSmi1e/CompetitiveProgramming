/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-28 08:07:44
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1890/problem/C
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
    if (n & 1) {
      cout << "-1\n";
      continue;
    }
    int c0 = 0;
    int c1 = 0;
    for (auto& c : s) {
      if (c == '0') {
        c0 += 1;
      } else {
        c1 += 1;
      }
    }
    if (c0 != c1) {
      cout << "-1\n";
      continue;
    }
    vector<int> res;
    while (true) {
      int i = 0, j = (int) s.size() - 1;
      bool ok = true;
      while (i < j) {
        if (s[i] == s[j]) {
          ok = false;
          if (s[i] == '0') {
            res.emplace_back(j + 1);
            s = s.substr(0, j + 1) + "01" + s.substr(j + 1);
          } else {
            res.emplace_back(i);
            s = s.substr(0, i) + "01" + s.substr(i);
          }
          break;
        } else {
          i += 1;
          j -= 1;
        }
      }
      if (ok) {
        break;
      }
    }
    cout << (int) res.size() << '\n';
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
