/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 02:45:21 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1932/problem/D
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
    char c;
    cin >> c;
    map<char, vector<int>> mp;
    for (int i = 0; i < 2 * n; i++) {
      string s;
      cin >> s;
      mp[s[1]].emplace_back((int) (s[0] - '0'));
    }
    int single = 0;
    for (auto& [s, arr] : mp) {
      sort(arr.begin(), arr.end());
      if (s != c) {
        single += ((int) arr.size()) & 1;
      }
    }
    if ((int) mp[c].size() < single || ((int) mp[c].size() - single) & 1) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    for (auto& [s, arr] : mp) {
      if (s != c) {
        while ((int) arr.size() > 1) {
          cout << arr[(int) arr.size() - 2] << s << ' ';
          cout << arr.back() << s << '\n';
          arr.pop_back();
          arr.pop_back();
        }
      } else {
        while ((int) arr.size() > single) {
          cout << arr[(int) arr.size() - 2] << s << ' ';
          cout << arr.back() << s << '\n';
          arr.pop_back();
          arr.pop_back();
        }
      }
    }
    for (auto& [s, arr] : mp) {
      if (s != c && (int) arr.size() > 0) {
        assert((int) arr.size() == 1);
        cout << arr.back() << s << ' ';
        cout << mp[c].back() << c << '\n';
        mp[c].pop_back();
      }
    }
  }
  return 0;
}
