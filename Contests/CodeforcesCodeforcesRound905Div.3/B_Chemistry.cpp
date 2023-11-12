/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 17:18:20
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1883/problem/B
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
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto& c : s) {
      cnt[(int) (c - 'a')] += 1;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
      odd += (cnt[i] & 1);
    }
    if (k < odd - 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
