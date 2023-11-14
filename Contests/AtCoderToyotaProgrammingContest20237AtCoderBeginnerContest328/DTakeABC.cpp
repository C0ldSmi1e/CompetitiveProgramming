/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 11:43:43
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_d
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

  string s;
  cin >> s;
  string stk;
  for (auto& c : s) {
    stk += c;
    if ((int) stk.size() >= 3 && stk.substr((int) stk.size() - 3, 3) == "ABC") {
      stk.pop_back();
      stk.pop_back();
      stk.pop_back();
    }
  }
  cout << stk << '\n';
  return 0;
}
