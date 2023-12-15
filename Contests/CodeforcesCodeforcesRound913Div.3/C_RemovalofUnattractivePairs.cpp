/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 07:21:32
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1907/problem/C
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto& c : s) {
      cnt[(int) (c - 'a')] += 1;
    }
    priority_queue<int> heap;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0) {
        heap.push(cnt[i]);
      }
    }
    while ((int) heap.size() > 1) {
      int x = heap.top();
      heap.pop();
      int y = heap.top();
      heap.pop();
      x -= 1;
      y -= 1;
      if (x > 0) {
        heap.push(x);
      }
      if (y > 0) {
        heap.push(y);
      }
    }
    if ((int) heap.size() == 0) {
      cout << "0\n";
      continue;
    }
    cout << (int) heap.top() << '\n';
  }
  return 0;
}
