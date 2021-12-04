#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    int res = 0;
    for (int mx = 0; mx <= 30; mx ++ )
    {
        for (int i = 1; i <= n; i ++ ) s[i] = (a[i] <= mx ? a[i] : 0);
        for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];
        int maxa = 0, mn = s[0];
        for (int i = 1; i <= n; i ++ )
        {
            maxa = max(maxa, s[i] - mn - mx);
            mn = min(mn, s[i]);
        }
        res = max(res, maxa);
    }
    cout << res << '\n';
    return 0;
}
