/**
 * Author: C0ldSmi1e
 * Created Time: 01/20/2024 05:43:21 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_b
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

  string s;
  cin >> s;
  int n = (int) s.size();
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = make_pair(s[i], i);
  }
  auto b = a;
  sort(b.begin(), b.end());
  cout << (a == b ? "Yes\n" : "No\n");
  return 0;
}
