// usage:
//  CountPairs(a, [&](int i, int j) { return i < j; });
//  Counts the number of pairs i < j such that func(a[i], a[j]) is true.
template <typename T, typename F = function<bool(const T &, const T &)>>
long long CountPairs(vector<T> a, const F &func) {
  int n = static_cast<int>(a.size());
  vector<T> temp(n);
  function<long long(int, int)> solve = [&](int l, int r) -> long long {
    if (l >= r) {
      return 0;
    }
    int mid = (l + r) >> 1;
    long long res = solve(l, mid) + solve(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid || j <= r) {
      if (i <= mid && (j > r || func(a[i], a[j]))) {
        temp[k++] = a[i++];
      } else {
        res += i - l;
        temp[k++] = a[j++];
      }
    }
    copy(temp.begin(), temp.begin() + k, a.begin() + l);
    return res;
  };
  return solve(0, n - 1);
}
