// 给定多个数组，要求从每个数组取一个数，求可以得到的第 k 大数
vector<int> merge(vector<int> a, vector<int> b)
{
    int n = a.size(), m = b.size();
    if (!n) return b;
    if (!m) return a;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    priority_queue<PII> heap;
    for (int i = 0; i < n; i ++ ) heap.push(make_pair(a[i] + b[0], 0));
    vector<int> res;
    for (int i = 0; i < n * m; i ++ )
    {
        auto [val, idx] = heap.top();
        heap.pop();
        res.emplace_back(val);
        if (idx + 1 < m) heap.push(make_pair(val - b[idx] + b[idx + 1], idx + 1));
    }
    return res;
}
