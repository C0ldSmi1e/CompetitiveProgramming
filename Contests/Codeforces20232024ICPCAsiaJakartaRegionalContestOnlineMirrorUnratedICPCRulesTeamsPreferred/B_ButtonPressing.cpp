/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-10 15:09:43
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1906/problem/B
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

  auto Get = [&](string s) -> set<int> {
    int n = (int) s.size();
    set<int> S;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        S.insert(i);
      }
    }
    while ((int) S.size() > 1) {
      auto it = prev(S.end());
      auto jt = prev(it);
      if ((int) S.size() == 2) {
        int i = (*it) - 1;
        int j = (*jt) - 1;
        S.erase(it);
        S.erase(jt);
        S.insert(i);
        if (j >= 0) {
          S.insert(j);
        }
        continue;
      }
      auto kt = prev(jt);
      if ((*kt) + 1 == *jt) {
        int i = (*it) - 1;
        S.erase(it);
        S.erase(jt);
        S.erase(kt);
        S.insert(i);
      } else {
        int i = (*it) - 1;
        int j = (*jt) - 1;
        S.erase(it);
        S.erase(jt);
        S.insert(i);
        S.insert(j);
      }
    }
    return S;
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s == t) {
      cout << "YES\n";
      continue;
    }
    auto S = Get(s);
    auto T = Get(t);
    if ((int) S.size() != (int) T.size()) {
      cout << "NO\n";
      continue;
    }
    if (*S.begin() == *T.begin() || *S.begin() + *T.begin() == n - 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
