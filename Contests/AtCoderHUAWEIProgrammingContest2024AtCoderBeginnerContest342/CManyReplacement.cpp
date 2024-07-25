/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 03:34:00 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc342/tasks/abc342_c
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

class Dsu {
 public:
  vector<int> p, sz;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int Get(int x) {
    return (x == p[x] ? x : (p[x] = Get(p[x])));
  }
  inline bool Unite(int x, int y) {
    x = Get(x);
    y = Get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int GetSize(int x) {
    return sz[Get(x)];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<set<int>> cc(26);
  for (int i = 0; i < 26; i++) {
    cc[i].emplace(i);
  }
  while (q--) {
    char a, b;
    cin >> a >> b;
    if (a == b) {
      continue;
    }
    for (auto& c : cc[(int) (a - 'a')]) {
      cc[(int) (b - 'a')].emplace(c);
    }
    cc[(int) (a - 'a')].clear();
  }
  for (auto& c : s) {
    int ccc = -1;
    for (int i = 0; i < 26; i++) {
      if (cc[i].count((int) (c - 'a')) > 0) {
        ccc = i;
      }
    }
    assert(ccc != -1);
    cout << (char) (ccc + 'a');
  }
  cout << '\n';
  return 0;
}
