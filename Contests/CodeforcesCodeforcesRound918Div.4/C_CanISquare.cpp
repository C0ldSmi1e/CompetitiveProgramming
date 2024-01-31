/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 06:41:51
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1915/problem/C
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
    vector<int> a(n);
    long long sum = 0;
    for (auto& u : a) {
      cin >> u;
      sum += u;
    }
    long long x = (long long) sqrt(sum);
    cout << (x * x == sum ? "YES\n" : "NO\n");
  }
  return 0;
}
