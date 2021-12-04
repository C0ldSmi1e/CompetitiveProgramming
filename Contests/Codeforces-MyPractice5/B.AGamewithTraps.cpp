#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, k, t;
    cin >> m >> n >> k >> t;
    vector<int> a(m + 1);
    a[0] = INF;
    for (int i = 1; i <= m; i ++ ) cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<tuple<int, int, int>> trap(k);
    for (auto &[l, r, d] : trap) cin >> l >> r >> d;
    auto check = [&](int x) -> bool
    {
        vector<pair<int, int>> seg;
        for (auto &[l, r, d] : trap)
            if (d > x)
                seg.emplace_back(l - 1, r);
        sort(seg.begin(), seg.end());
        int len = 0, pos = -INF;
        for (auto &[l, r] : seg)
            if (r > pos)
            {
                if (l < pos) len += r - pos;
                else len += r - l;
                pos = r;
            }
        return len * 2 + n + 1 <= t;
    };
    int l = 0, r = m;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(a[mid])) l = mid;
        else r = mid - 1;
    }
    cout << r << '\n';
    return 0;
}
