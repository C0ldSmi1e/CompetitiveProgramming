/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 10:18:47
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2308
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

  const int N = (int) 1e6 + 300000;
  vector<bool> st(N);
  st[0] = st[1] = true;
  for (int i = 2; i < N; i++) {
    for (int j = 2 * i; j < N; j += i) {
      st[j] = true;
    }
  }
  vector<int> primes;
  for (int i = 0; i < N; i++) {
    if (!st[i]) {
      primes.emplace_back(i);
    }
  }
  vector<int> b;
  for (auto& u : primes) {
    long long x = u;
    while (x <= N) {
      b.emplace_back(x);
      x *= u;
    }
  }
  sort(b.begin(), b.end());
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      S.insert(x);
    }
    if (*S.begin() != 1) {
      cout << "1\n";
      continue;
    }
    for (auto& u : b) {
      if (S.find(u) == S.end()) {
        cout << u << '\n';
        break;
      }
    }
  }
  return 0;
}
