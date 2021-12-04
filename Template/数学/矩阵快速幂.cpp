// res = a * b
// a is a (n*m) matrix
// b is a (m*r) matrix
// res is a (n*r) matrix
template <typename A>
vector<vector<A>> mul(vector<vector<A>> &a, vector<vector<A>> &b) {
  int n = (int) a.size();
  int m = (int) b.size();
  assert(n > 0 && m > 0 && m == (int) a[0].size());
  int r = (int) b[0].size();
  vector<vector<A>> res(n, vector<A>(r, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < r; k++) {
        res[i][k] += a[i][j] * b[j][k];
      }
    }
  }
  return res;
}

template <typename A>
vector<vector<A>> add(vector<vector<A>> &a, vector<vector<A>> &b) {
  int n = (int) a.size();
  assert(n > 0 && n == (int) b.size());
  int m = (int) a[0].size();
  assert(m == (int) b[0].size());
  vector<vector<A>> res;
  for (int i = 0; i < n; i++) {
    assert(m == (int) a[i].size());
    assert(m == (int) b[i].size());
    for (int j = 0; j < m; j++) {
      res[i][j] = a[i][j] + b[i][j];
    }
  }
  return res;
}

template <typename A>
vector<vector<A>> sub(vector<vector<A>> &a, vector<vector<A>> &b) {
  int n = (int) a.size();
  assert(n > 0 && n == (int) b.size());
  int m = (int) a[0].size();
  assert(m == (int) b[0].size());
  vector<vector<A>> res;
  for (int i = 0; i < n; i++) {
    assert(m == (int) a[i].size());
    assert(m == (int) b[i].size());
    for (int j = 0; j < m; j++) {
      res[i][j] = a[i][j] - b[i][j];
    }
  }
  return res;
}

template <typename A, typename B>
vector<vector<A>> qp(vector<vector<A>> &a, const B &b) {
  assert(b >= 0);
  int n = (int) a.size();
  assert(n > 0 && n == (int) a[0].size());
  vector<vector<A>> x = a, res(n, vector<A>(n, 0));
  for (int i = 0; i < n; i++) {
    res[i][i] = 1;
  }
  B p = b;
  while (p > 0) {
    if (p & 1) {
      res = mul(res, x);
    }
    x = mul(x, x);
    p >>= 1;
  }
  return res;
}
