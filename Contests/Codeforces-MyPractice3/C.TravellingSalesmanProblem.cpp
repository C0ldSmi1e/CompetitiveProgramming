#include <vector>
#include <cassert>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 2e9;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), c(n);
    for (int i = 0; i < n; i ++ ) cin >> a[i] >> c[i];
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y)
    {
        return a[x] < a[y];
    });
    long long res = accumulate(c.begin(), c.end(), 0LL), mx = -INF;
    for (int j = 0; j < n; j ++ )
    {
        int i = order[j];
        cout << a[i] - mx << '\n';
        if (j) res += max(0LL, a[i] - mx);
        mx = max(mx, a[i] + c[i]);
    }
    cout << res << '\n';
    return 0;
}
