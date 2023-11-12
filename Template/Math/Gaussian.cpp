// a[N][N]是增广矩阵
int gauss() {
  int c, r;
  for (c = 0, r = 0; c < n; c++) {
    int t = r;
    for (int i = r; i < n; i++) {
      // 找到绝对值最大的行
      if (fabs(a[i][c]) > fabs(a[t][c])) {
        t = i;
      }
    }
    if (fabs(a[t][c]) < eps) {
      continue;
    }
    for (int i = c; i <= n; i++) {
      // 将绝对值最大的行换到最顶端
      swap(a[t][i], a[r][i]);
    }
    for (int i = n; i >= c; i--) {
      // 将当前上的首位变成1
      a[r][i] /= a[r][c];
    }
    for (int i = r + 1; i < n; i++) {
      // 用当前行将下面所有的列消成0
      if (fabs(a[i][c]) > eps) {
        for (int j = n; j >= c; j--) {
          a[i][j] -= a[r][j] * a[i][c];
        }
      }
    }
    r++;
  }
  if (r < n) {
    for (int i = r; i < n; i ++ ) {
      if (fabs(a[i][n]) > eps) {
        // 无解
        return 2; 
      }
    }
    // 有无穷多组解
    return 1; 
  }
  for (int i = n - 1; i >= 0; i -- )
      for (int j = i + 1; j < n; j ++ )
          a[i][n] -= a[i][j] * a[j][n];
  // 有唯一解
  return 0; 
}
