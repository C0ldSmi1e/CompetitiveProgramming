/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 03:55:33 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc342/tasks/abc342_d
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

  int M = 200010;
  vector<bool> st(M);
  for (int i = 2; i < M; i++) {
    for (int j = i + i; j < M; j += i) {
      st[j] = true;
    }
  }
  vector<int> primes;
  for (int j = 2; j < M; j++) {
    if (!st[j]) {
      primes.emplace_back(j);
    }
  }
  const int N = (int) primes.size();
  debug(N);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    mp[primes[i]] = i;
  }
  long long ans = 0;
  int zero = 0;
  bitset<20000> one("1");
  unordered_map<bitset<20000>, int> mmp;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    if (x == 0) {
      ans += i;
      zero += 1;
      continue;
    }
    ans += zero;
    map<int, int> factors;
    for (int j = 2; j <= x / j; j++) {
      while (x % j == 0) {
        factors[j] += 1;
        x /= j;
      }
    }
    if (x > 1) {
      factors[x] = 1;
    }
    bitset<20000> b("0");
    for (auto& [fac, cnt] : factors) {
      if (cnt & 1) {
        b |= (one << (mp[fac]));
      }
    }
    ans += mmp[b];
    mmp[b] += 1;
  }
  cout << ans << '\n';
  return 0;
}
