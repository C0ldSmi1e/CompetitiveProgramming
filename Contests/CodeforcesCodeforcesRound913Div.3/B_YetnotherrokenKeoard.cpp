/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 07:14:07
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1907/problem/B
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
    vector<pair<char, int>> up;
    vector<pair<char, int>> low;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        if ((int) low.size() > 0) {
          low.pop_back();
        }
        continue;
      }
      if (s[i] == 'B') {
        if ((int) up.size() > 0) {
          up.pop_back();
        }
        continue;
      }
      if (s[i] >= 'a' && s[i] <= 'z') {
        low.emplace_back(make_pair(s[i], i));
        continue;
      }
      up.emplace_back(make_pair(s[i], i));
    }
    vector<pair<int, char>> res;
    for (auto& [c, i] : up) {
      res.emplace_back(make_pair(i, c));
    }
    for (auto& [c, i] : low) {
      res.emplace_back(make_pair(i, c));
    }
    sort(res.begin(), res.end());
    for (auto& [i, c] : res) {
      cout << c;
    }
    cout << '\n';
  }
  return 0;
}
