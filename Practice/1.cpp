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
    multiset<int> S{0, 3, 0, 1, 2, 0, 2, 5};
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (S.count(x)) {
        S.erase(S.find(x));
        if ((int) S.size() == 0) {
          ans = i;
        }
      }
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}
