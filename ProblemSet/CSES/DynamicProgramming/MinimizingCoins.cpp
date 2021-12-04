#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 0x3f3f3f3f;
 
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<int>> f(n + 1, vector<int>(x + 1, INF));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      f[i][j] = min(f[i][j], f[i - 1][j]);
      if (j >= a[i - 1]) {
        f[i][j] = min(f[i][j], f[i][j - a[i - 1]] + 1);
      }
    }
  }
  if (f[n][x] >= INF) {
    cout << "-1\n";
  } else {
    cout << f[n][x] << '\n';
  }
  return 0;
}
