// longest increasing subsequence
template <typename A>
vector<A> Lis(vector<A> &a) {
  int n = static_cast<int>(a.size());
  assert(n > 0);
  vector<A> q{a[0]};
  vector<int> f(n);
  for (int i = 1; i < n; i ++ ) {
    if (a[i] > q.back()) {
      q.emplace_back(a[i]);
      f[i] = (int) q.size();
    } else {
      int pos = (int) (lower_bound(q.begin(), q.end(), a[i]) - q.begin());
      q[pos] = a[i];
      f[i] = pos + 1;
    }
  }
  return q;
}

// longest non-decreasing subsequence
template <typename A>
vector<A> Lnds(vector<A> &a) {
  int n = static_cast<int>(a.size());
  assert(n > 0);
  vector<A> q{a[0]};
  vector<int> f(n);
  for (int i = 1; i < n; i ++ ) {
    if (a[i] >= q.back()) {
      q.emplace_back(a[i]);
      f[i] = (int) q.size();
    } else {
      int pos = (int) (upper_bound(q.begin(), q.end(), a[i]) - q.begin());
      q[pos] = a[i];
      f[i] = pos + 1;
    }
  }
  return q;
}


// longest decreasing subsequence
template <typename A>
vector<A> Lds(vector<A> &a) {
  int n = static_cast<int>(a.size());
  assert(n > 0);
  vector<A> q{a[0]};
  vector<int> f(n);
  for (int i = 1; i < n; i ++ ) {
    if (a[i] < q.back()) {
      q.emplace_back(a[i]);
      f[i] = (int) q.size();
    } else {
      int pos = (int) (lower_bound(q.begin(), q.end(), a[i], greater<int>()) - q.begin());
      q[pos] = a[i];
      f[i] = pos + 1;
    }
  }
  return q;
}

// longest non-increasing subsequence
template <typename A>
vector<A> Lnis(vector<A> &a) {
  int n = static_cast<int>(a.size());
  assert(n > 0);
  vector<A> q{a[0]};
  vector<int> f(n);
  for (int i = 1; i < n; i ++ ) {
    if (a[i] <= q.back()) {
      q.emplace_back(a[i]);
      f[i] = (int) q.size();
    } else {
      int pos = (int) (upper_bound(q.begin(), q.end(), a[i], greater<int>()) - q.begin());
      q[pos] = a[i];
      f[i] = pos + 1;
    }
  }
  return q;
}


反链定理：
最长上升子序列的个数=最长不上升子序列的长度，反之亦然。
最长下降子序列的个数=最长不下降子序列的长度，反之亦然。

// 最长公共子序列
// 下标从 1 开始
// n, m 分别为两个序列长度， f[][] 初始值为 0 
int Lcs() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      f[i][j] = max(f[i][j], f[i - 1][j - 1] + (int) (a[i] == b[j]));
    }
  }
  return f[n][m];
}

// 最长公共上升子序列
// 下标从 1 开始
int Lcis() {
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      f[i][j] = f[i - 1][j];
      if (a[i] == b[j]) {
        f[i][j] = max(f[i][j], mx + 1);
      }
      if (a[i] > b[j]) {
        mx = max(mx, f[i - 1][j]);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i ++ ) {
    res = max(res, f[n][i]);
  }
  return res;
} 

求最长回文子串用 Manacher 算法
求最长回文子序列将原序列翻转，与原序列求最长公共子序列
