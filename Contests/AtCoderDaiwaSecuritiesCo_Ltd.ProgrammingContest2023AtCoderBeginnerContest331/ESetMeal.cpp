// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc331/tasks/abc331_e
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
vector<array<int, 3>> MultiMerge(vector<T> a, vector<T> b, int k) {
  int n = (int) a.size(), m = (int) b.size();
  assert(n >= 0 && m >= 0);
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  debug(a);
  debug(b);
  priority_queue<array<int, 4>> heap;
  for (int i = 0; i < n; i++) {
    heap.push({a[i].first + b[0].first, a[i].second, b[0].second, 0});
  }
  vector<array<int, 3>> res;
  for (int it = 0; it < k; it++) {
    auto [val, i, j, idx] = heap.top();
    debug(val, i, j, idx);
    heap.pop();
    res.push_back({val, i, j});
    if (idx + 1 < m) {
      heap.push({val - b[idx].first + b[idx + 1].first, i, b[idx + 1].second, idx + 1});
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vector<pair<int, int>> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  set<pair<int, int>> S;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    S.insert(make_pair(x, y));
  }
  auto arr = MultiMerge(a, b, k + 1);
  debug(S);
  debug(arr);
  for (auto& [x, i, j] : arr) {
    if (!S.count(make_pair(i, j))) {
      cout << x << '\n';
      break;
    }
  }
  return 0;
}
