// 一维
// 以最大值为例
// 最小值只需要改成 min 即可
const int N = 200010, M = 18;

int n, m, a[N];
int f[N][M];
int LOG2[N];

void init() {
  for (int i = 2; i < N; i++) {
    LOG2[i] = LOG2[i / 2] + 1;
  }
  for (int j = 0; j < M; j ++ ) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      if (!j) {
        f[i][j] = a[i];
      } else {
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
}

int query(int l, int r) {
  int len = r - l + 1;
  int k = LOG2[len];
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}



// 二维
// 以最大值为例
// 最小值只需要改成 min 即可
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j ++ ) {
      dp[i][j][0][0] = val[i][j];
    }
  }
  for (int i = 0; (1 << i) <= n; i++) {
    for (int j = 0; (1 << j) <= m; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      for (int row = 1; row + (1 << i) - 1 <= n; row++) {
        for (int col = 1; col + (1 << j) - 1 <= m; col++) {
            // 当 x 或 y 等于 0 的时候，就相当于一维的 RMQ 了
          if (i == 0) {
            dp[row][col][i][j] = max(dp[row][col][i][j - 1], dp[row][col + (1 << (j - 1))][i][j - 1]);
          } else if (j == 0) {
            dp[row][col][i][j] = max(dp[row][col][i - 1][j], dp[row + (1 << (i - 1))][col][i - 1][j]);
          } else {
            dp[row][col][i][j] = max(dp[row][col][i][j - 1], dp[row][col + (1 << (j - 1))][i][j - 1]);
          }
        }
      }
    }
  }
}

int query(int x1, int y1, int x2, int y2) {
  int kx = 31 - __builtin_clz(x2 - x1 + 1);
  int ky = 31 - __builtin_clz(y2 - y1 + 1);
  int m1 = dp[x1][y1][kx][ky];
  int m2 = dp[x2 - (1 << kx) + 1][y1][kx][ky];
  int m3 = dp[x1][y2 - (1 << ky) + 1][kx][ky];
  int m4 = dp[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
  return max(max(m1, m2), max(m3, m4));
}
