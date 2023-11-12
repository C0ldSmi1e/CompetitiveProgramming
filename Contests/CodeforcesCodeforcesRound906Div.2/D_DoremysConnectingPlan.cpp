/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-28 08:27:47
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1890/problem/D
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
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int getSize(int x) {
    return sz[get(x)];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, c;
    cin >> n >> c;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    long long s1 = a[0];
    vector<pair<long long, int>> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
      b[i] = make_pair(1LL * (i + 1) * c - a[i + 1], i + 2);
    }
    sort(b.begin(), b.end());
    bool flag = true;
    for (auto& [s, i] : b) {
      if ((s1 + a[i - 1]) < 1LL * i * c) {
        flag = false;
        break;
      }
      s1 += a[i - 1];
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
