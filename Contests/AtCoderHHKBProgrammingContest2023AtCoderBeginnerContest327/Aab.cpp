/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-04 05:01:39
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc327/tasks/abc327_a
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

  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s.find("ab") == string::npos && s.find("ba") == string::npos) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  return 0;
}
