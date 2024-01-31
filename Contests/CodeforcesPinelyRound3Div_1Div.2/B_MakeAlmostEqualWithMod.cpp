/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-23 07:18:38
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1909/problem/B
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
    vector<long long> a(n);
    bool odd = false;
    bool even = false;
    for (auto& u : a) {
      cin >> u;
      odd |= (u % 2 == 1);
      even |= (u % 2 == 0);
    }
    if (odd && even) {
      cout << "2\n";
      continue;
    }
    const long long INF = (long long) 1e18;
    set<long long> cand{a.begin(), a.end()};
    for (long long i = 2; i < INF; i *= 2) {
      cand.insert(i);
    }
    for (long long i = 3; i < INF; i *= 3) {
      cand.insert(i);
    }
    for (long long i = 2; i <= 100; i++) {
    }
    for (auto& i : cand) {
      set<long long> S;
      for (auto& u : a) {
        S.insert(u % i);
      }
      if ((int) S.size() == 2) {
        cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}
