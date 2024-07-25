/**
 * Author: C0ldSmi1e
 * Created Time: 07/24/2024 10:49:47 PM
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
  cout << accumulate(a.begin(), a.end(), 0) << '\n';
  return 0;
}
