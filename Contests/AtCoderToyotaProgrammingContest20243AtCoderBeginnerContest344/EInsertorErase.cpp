// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc344/tasks/abc344_e
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

  const int N = 400010;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  int head = 0, tail = 1;
  int idx = 2;
  vector<int> l(N, -1);
  vector<int> r(N, -1);
  vector<int> v(N, -1);
  l[head] = -1, r[head] = tail;
  l[tail] = head, r[tail] = -1;
  map<int, int> mp;
  auto Insert = [&](int p, int x) -> void {
    v[idx] = x;
    r[idx] = r[p];
    l[r[p]] = idx;
    l[idx] = p;
    r[p] = idx;
    mp[x] = idx;
    idx += 1;
  };
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      Insert(mp[a[i - 1]], a[i]);
    } else {
      Insert(head, a[i]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      Insert(mp[x], y);
    } else {
      int x;
      cin >> x;
      r[l[mp[x]]] = r[mp[x]];
      l[r[mp[x]]] = l[mp[x]];
    }
  }
  int ptr = r[head];
  while (ptr != tail) {
    cout << v[ptr] << ' ';
    ptr = r[ptr];
  }
  cout << '\n';
  return 0;
}
