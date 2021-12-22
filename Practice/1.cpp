#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  const int N = 200010;
  vector<int> pos(N);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    pos[a[i]] = i + n;
  }
  const int K = 61;
  const long long INF = (long long) 2e18;
  vector<vector<long long>> len(n, vector<long long>(K, INF));
  for (int i = n - 1; i >= 0; i--) {
    len[i][0] = pos[a[i]] - i + 1;
    pos[a[i]] = i;
  }
  for (int j = 1; j < K; j++) {
    for (int i = 0; i < n; i++) {
      len[i][j] = min(INF, len[i][j - 1] + len[(i + len[i][j - 1]) % n][j - 1]);
    }
  }
  long long cur = 0;
  for (int j = K - 1; j >= 0; j--) {
    if (cur + len[cur % n][j] <= k * n) {
      cur += len[cur % n][j];
    }
  }
  vector<bool> st(N);
  vector<int> res;
  while (cur < k * n) {
    if (st[a[cur % n]]) {
      while (true) {
        int v = res.back();
        st[v] = false;
        res.pop_back();
        if (v == a[cur % n]) {
          break;
        }
      }
    } else {
      res.emplace_back(a[cur % n]);
      st[a[cur % n]] = true;
    }
    ++cur;
  }
  int rn = int(res.size());
  for (int i = 0; i < rn; i++) {
    cout << res[i] << " \n"[i == rn - 1];
  }
  return 0;
}
