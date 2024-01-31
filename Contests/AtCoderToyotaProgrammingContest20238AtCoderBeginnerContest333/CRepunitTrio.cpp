/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 15:50:45
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc333/tasks/abc333_c
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

  long long t = 1;
  vector<long long> a;
  for (int i = 0; i < 15; i++) {
    a.emplace_back(t);
    t = t * 10 + 1;
  }
  debug(a);
  vector<long long> b;
  for (auto& u : a) {
    for (auto& v : a) {
      for (auto& w : a) {
        b.emplace_back(u + v + w);
      }
    }
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  debug(b);
  debug((int) b.size());
  int n;
  cin >> n;
  cout << b[n - 1] << '\n';
  return 0;
}
