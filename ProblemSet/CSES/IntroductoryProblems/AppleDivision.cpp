/**
 * Author: Daniel
 * Created Time: 2021-06-09 15:03:05
**/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long res = (long long) 4e18;
  for (int mask = 0; mask < 1 << n; mask++) {
    vector<long long> tot(2);
    for (int bit = 0; bit < n; bit++) {
      tot[(mask >> bit) & 1] += a[bit];
    }
    res = min(res, abs(tot[0] - tot[1]));
  }
  cout << res << '\n';
  return 0;
}
