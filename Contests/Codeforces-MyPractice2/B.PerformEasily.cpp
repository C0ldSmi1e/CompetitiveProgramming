#include <vector>
#include <iostream>
#include <algorithm>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const int N = 100010, M = 6;
const LL INF = 4e18;

int n;
int a[M], b[N];

LL min_sum_of_max(vector<PLL> &a)
{
    int n = a.size();
    if (n == 0) return 0;
    if (n == 1) return min(a[0].first, a[0].second);
    sort(a.begin(), a.end());
    LL mx = a.back().second, res = a.back().first;
    for (int i = n - 2; i >= 0; i -- )
    {
        res = min(res, a[i].first + mx);
        mx = max(mx, a[i].second);
    }
    res = min(res, mx);
    return res;
}

LL solve(LL base)
{
    vector<PLL> A;
    for (int j = 1; j < n; j ++ )
    {
        PLL t{INF, INF};
        for (int i = 0; i < M; i ++ )
            if (b[j] - a[i] >= base) t.S = min(t.S, b[j] - a[i] - base);
            else t.F = min(t.F, base - (b[j] - a[i]));
        A.emplace_back(t);
    }
    return min_sum_of_max(A);
}

int main()
{
    for (int i = 0; i < M; i ++ ) cin >> a[i];
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> b[i];
    LL res = INF;
    for (int i = 0; i < M; i ++ ) res = min(res, solve(b[0] - a[i]));
    cout << res << '\n';
    return 0;
}
