/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-02 11:10:04
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc331/tasks/abc331_c
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

  int n;
  cin >> n;
  const int N = 1000010;
  vector<vector<int>> idx(N);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]].emplace_back(i);
  }
  long long sum = 0;
  vector<long long> res(n);
  for (int i = N - 1; i >= 0; i--) {
    for (auto& j : idx[i]) {
      res[j] = sum;
    }
    sum += 1ll * i * (int) idx[i].size();
  }
  for (auto& u : res) {
    cout << u << ' ';
  }
  cout << '\n';
  return 0;
}
