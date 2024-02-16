/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 06:38:49 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START121A/problems/FREEQ
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

  const int N = 1000010;
  vector<bool> st(N);
  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      st[j] = true;
    }
  }
  vector<int> primes;
  for (int i = 2; i < N; i++) {
    if (!st[i]) {
      primes.emplace_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> ans;
    if (n & 1) {
      ans.emplace_back(1);
    }
    for (int j = 0; (int) ans.size() < n; j++) {
      ans.emplace_back(primes[j]);
      ans.emplace_back(primes[j]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
