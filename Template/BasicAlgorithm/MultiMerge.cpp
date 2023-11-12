// 给定多个数组，要求从每个数组取一个数，求可以得到的第 k 大数
template <typename T>
vector<T> MultiMerge(vector<T> a, vector<T> b) {
  int n = (int) a.size(), m = (int) b.size();
  assert(n >= 0 && m >= 0);
  if (!n) {
    return b;
  }
  if (!m) {
    return a;
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  priority_queue<pair<T, int>> heap;
  for (int i = 0; i < n; i++) {
    heap.push(make_pair(a[i] + b[0], 0));
  }
  vector<T> res;
  for (int i = 0; i < n * m; i++) {
    auto [val, idx] = heap.top();
    heap.pop();
    res.emplace_back(val);
    if (idx + 1 < m) {
      heap.push(make_pair(val - b[idx] + b[idx + 1], idx + 1));
    }
  }
  return res;
}
