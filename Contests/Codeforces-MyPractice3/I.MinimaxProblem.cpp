#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> a[i][j];
    pair<int, int> res{-1, -1};
    auto check = [&](int x) -> bool
    {
        vector<int> idx(1 << m, -1);
        for (int i = 0; i < n; i ++ )
        {
            int mask = 0;
            for (int j = 0; j < m; j ++ )
                if (a[i][j] >= x)
                    mask |= (1 << j);
            idx[mask] = i;
        }
        for (int i = 0; i < 1 << m; i ++ )
            for (int j = 0; j < 1 << m; j ++ )
                if (idx[i] != -1 && idx[j] != -1 && (i | j) == (1 << m) - 1)
                {
                    res = make_pair(idx[i], idx[j]);
                    return true;
                }
        res = {-1, -1};
        return false;
    };
    int l = 0, r = 1e9 + 10;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    check(r);
    cout << res.first + 1 << ' ' << res.second + 1 << '\n';
    return 0;
}
