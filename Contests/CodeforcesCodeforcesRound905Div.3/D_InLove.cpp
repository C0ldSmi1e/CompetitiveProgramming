/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 14:31:59
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1883/problem/D
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

  int T;
  cin >> T;
  multiset<int> L;
  multiset<int> R;
  while (T--) {
    char t;
    int a, b;
    cin >> t >> a >> b;
    if (t == '+') {
      L.insert(a);
      R.insert(b);
    } else {
      assert(L.find(a) != L.end());
      assert(R.find(b) != R.end());
      L.erase(L.find(a));
      R.erase(R.find(b));
    }
    if ((int) L.size() <= 1) {
      cout << "NO\n";
      continue;
    }
    int mx = *prev(L.end());
    int mn = *R.begin();
    if ((int) L.size() > 1 && mx > mn) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
