/**
 * Author: C0ldSmi1e
 * Created Time: 01/24/2024 06:48:07 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START118B/problems/XORRY2
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
    int x;
    cin >> x;
    vector<int> bits;
    for (int bit = 0; bit < 30; bit++) {
      if ((x >> bit) & 1) {
        bits.emplace_back(bit);
      }
    }
    if ((int) bits.size() == 1) {
      cout << "1\n";
      continue;
    }
    bits.pop_back();
    int s = bits.back();
    bits.pop_back();
    s -= (int) bits.size();
    int ans = 1;
    while (s > 0) {
      ans <<= 1;
      s -= 1;
    }
    cout << ans << '\n';
  }
  return 0;
}

