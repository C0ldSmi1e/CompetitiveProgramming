#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  map<pair<int, long long>, long long> f;
  function<long long(int, long long)> dp = [&](int i, long long j) -> long long {
    if (i == 0 || j == 0) {
      return j;
    }
    if (f.count(make_pair(i, j)) != 0) {
      return f[make_pair(i, j)];
    }
    long long res = dp(i - 1, j % a[i]) + j / a[i];
    res = min(res, dp(i - 1, (a[i] - j % a[i]) % a[i]) + (j + a[i] - 1) / a[i]);
    return f[make_pair(i, j)] = res;
  };
  cout << dp(n - 1, x) << '\n';
  return 0;
}
