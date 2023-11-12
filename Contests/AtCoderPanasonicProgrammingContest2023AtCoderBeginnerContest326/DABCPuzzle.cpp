// time-limit: 4000
// problem-url: https://atcoder.jp/contests/abc326/tasks/abc326_d
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

  int n;
  cin >> n;
  string r, c;
  cin >> r >> c;
  string p = "ABC";
  while ((int) p.size() < n) {
    p += '.';
  }
  auto Get_first = [&](string& s) -> char {
    int i = 0;
    while (i < n && s[i] == '.') {
      i += 1;
    }
    if (i >= n) {
      return '#';
    }
    return s[i];
  };
  vector<vector<string>> cand(n);
  for (int i = 0; i < n; i++) {
    sort(p.begin(), p.end());
    do {
      if (Get_first(p) == r[i]) {
        cand[i].emplace_back(p);
      }
    } while (next_permutation(p.begin(), p.end()));
  }
  vector<string> g(n);
  auto Dfs = [&](auto& self, int i) -> bool {
    if (i >= n) {
      bool flag = true;
      for (int j = 0; j < n; j++) {
        string t;
        for (int k = 0; k < n; k++) {
          t += g[k][j];
        }
        flag &= Get_first(t) == c[j];
        vector<int> cnt(3);
        for (auto& x : t) {
          if (x != '.') {
            cnt[(int) (x - 'A')] += 1;
          }
        }
        flag &= (cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1);
      }
      return flag;
    }
    for (auto& s : cand[i]) {
      g[i] = s;
      if (self(self, i + 1)) {
        return true;
      }
    }
    return false;
  };
  if (!Dfs(Dfs, 0)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (auto& s : g) {
    cout << s << '\n';
  }
  return 0;
}
