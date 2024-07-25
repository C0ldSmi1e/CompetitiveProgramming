/**
 * Author: C0ldSmi1e
 * Created Time: 02/29/2024 08:07:46 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1937/problem/C
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  auto Ask = [&](int a, int b, int c, int d) -> int {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char ans;
    cin >> ans;
    if (ans == '=') {
      return 0;
    }
    if (ans == '>') {
      return 1;
    }
    return -1;
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << "! 0 1" << endl;
      continue;
    }
    int mxi = 0;
    for (int i = 1; i < n; i++) {
      if (Ask(i, i, mxi, mxi) > 0) {
        mxi = i;
      }
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (i != mxi) {
        if ((int) b.size() == 0) {
          b.emplace_back(i);
          continue;
        }
        int c = Ask(i, mxi, b.back(), mxi);
        if (c == 0) {
          b.emplace_back(i);
        }
        if (c == 1) {
          b.clear();
          b.emplace_back(i);
        }
      }
    }
    int mni = b[0];
    for (int i = 1; i < (int) b.size(); i++) {
      if (Ask(b[i], b[i], mni, mni) < 0) {
        mni = b[i];
      }
    }
    cout << "! " << mni << ' ' << mxi << endl;
  }
  return 0;
}
