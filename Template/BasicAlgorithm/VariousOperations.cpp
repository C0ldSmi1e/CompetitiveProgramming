// 有若干个数对 (a, b) ，将 a 放入 A ，或者将 b 放入 B
// 使得 max(A) + max(B) 最小
int MinSumOfMax(vector<pair<int, int>> &a) {
  int n = (int) a.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return min(a[0].first, a[0].second);
  }
  sort(a.begin(), a.end());
  int mx = a.back().second, res = a.back().first;
  for (int i = n - 2; i >= 0; i--) {
    res = min(res, a[i].first + mx);
    mx = max(mx, a[i].second);
  }
  res = min(res, mx);
  return res;
}


// 64 位乘法取模
long long mul(long long a, long long b, long long mod) {
	long long res = 0;
	while (b > 0) {
		if (b & 1) res = (res + a) % mod;
		a = a * 2 % mod;
		b >>= 1;
	}
	return res;
}




// 离散化
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
// 找到第一个大于等于x的位置
int find(int x) {
  int l = 0, r = (int) alls.size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (alls[mid] >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return r + 1; // 映射到1, 2, ...n
}




// 前缀和与差分
// 一维前缀和
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]

// 二维前缀和
// S[i, j] = 第i行j列格子左上部分所有元素的和
// 以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]

// 一维差分
// 给区间[l, r]中的每个数加上c
B[l] += c, B[r + 1] -= c
//直接用定义
B[i] = a[i] - a[i - 1]

// 二维差分
// 给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：
S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c


/**

 * __builtin_ffs(x)：返回x中最后一个为1的位是从后面向前第几位
 * __builtin_popcount(x)：x中1的个数
 * __builtin_ctz(x)：x末尾0的个数，x=0时未定义
 * __builtin_clz(x)：x前导0的个数，x=0时未定义
 * __builtin_parity(x)：x中1的奇偶性
 * 其中x是unsigned int类型

**/

// 枚举某个数的二进制表示下的子集（不包括 0 ）
// 包含 x ：
for (int mask = x; mask; mask = (mask - 1) & x)
// 不包含 x ：
for (int mask = x - 1 & x; mask; mask = (mask - 1) & x)
// 以下效率更高一点（不包含 x ）：
for (int bit = 0; bit < bit_cnt; bit++) {
  for (int mask = 0; mask < (1 << bit_cnt); mask++) {
    if (mask & (1 << bit)) {
      // (mask ^ (1 << bit)) 为结果
    }
  }
}

// 在 O(3^n) 内遍历 [1,2^n) 的所有数的子集
for (int m = 0; m < (1 << n); ++m) {
  for (int s = m; s; s = (s-1) & m) {
    // s is m's submask
  }
}
