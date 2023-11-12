// time-limit: 2000
// problem-url: 
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
    int n;
    cin >> n;
    if (n <= 2) {
      cout << "Bob\n";
      continue;
    }
    cout << ((n & 1) ? "Alice\n" : "Bob\n");
  }
  return 0;
}
