/**
 * Author: C0ldSmi1e
 * Created Time: 03/20/2025 07:54:49 AM
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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = (a[i] - i + n - 1) / n;
  }
  int mn = (int) 1e9;
  int mni = n;
  for (int i = 0; i < n; i++) {
    if (b[i] < mn) {
      mn = b[i];
      mni = i;
    }
  }
  cout << mni + 1 << '\n';
  return 0;
}
