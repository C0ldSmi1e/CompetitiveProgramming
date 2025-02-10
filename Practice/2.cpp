/**
 * Author: C0ldSmi1e
 * Created Time: 02/09/2025 11:56:57 AM
**/

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
    for (auto& u : a) {
      cin >> u;
    }
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    long long sor = 0;
    for (auto& u : a) {
      sor ^= u;
    }
    vector<long long> ans;
    long long add = (1ll << 50) + (sum & 1);
    ans.emplace_back(add);
    sum += add;
    sor ^= add;
    ans.emplace_back((2 * sor - sum) / 2);
    ans.emplace_back((2 * sor - sum) / 2);
    cout << (int) ans.size() << '\n';
    for (auto& u : ans) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
