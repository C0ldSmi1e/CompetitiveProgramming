#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 2010;

int n, m;
int a[N], b[N], c[N], d[N];

int min_sum_of_max(vector<PII> &a)
{
    int n = a.size();
    if (n == 0) return 0;
    if (n == 1) return min(a[0].first, a[0].second);
    sort(a.begin(), a.end());
    int mx = a.back().second, res = a.back().first;
    for (int i = n - 2; i >= 0; i -- )
    {
        res = min(res, a[i].first + mx);
        mx = max(mx, a[i].second);
    }
    res = min(res, mx);
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> a[i] >> b[i];
    for (int i = 0; i < m; i ++ ) cin >> c[i] >> d[i];
    vector<PII> A;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (a[i] <= c[j] && b[i] <= d[j])
                A.emplace_back(c[j] - a[i] + 1, d[j] - b[i] + 1);
    cout << min_sum_of_max(A) << '\n';
    return 0;
}
