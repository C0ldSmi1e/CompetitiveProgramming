/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2025 07:31:31 AM
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

  int b, q, l, m;
  cin >> b >> q >> l >> m;
  vector<long long> a(m);
  for (auto& u : a) {
    cin >> u;
  }
  set<int> S{a.begin(), a.end()};
  if (q == 0) {
    if (!S.count(0)) {
      cout << "inf\n";
      return 0;
    }
    if (!S.count(b)) {
      cout << "1\n";
      return 0;
    }
    cout << "0\n";
    return 0;
  }
  if (q == 1) {
    if (!S.count(b)) {
      cout << "inf\n";
    } else {
      cout << "0\n";
    }
    return 0;
  }
  if (q == -1) {
    if (S.count(b) && S.count(-b)) {
      cout << "0\n";
    } else {
      cout << "inf\n";
    }
    return 0;
  }
  if (q < 0) {
    cout << "inf\n";
    return 0;
  }
  vector<long long> seq{b};
  while (true) {
    long long x = 1ll * seq.back() * q;
    if (x <= l) {
      seq.emplace_back(1ll * seq.back() * q);
      continue;
    }
    break;
  }
  set<long long> ans{seq.begin(), seq.end()};
  debug(ans);
  for (auto& u : S) {
    ans.erase(u);
  }
  cout << (int) ans.size() << '\n';
  return 0;
}
