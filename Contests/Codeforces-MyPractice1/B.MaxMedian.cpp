#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, k;
int a[N], s[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    int l = 1, r = n;
    auto check = [&](int x) -> bool
    {
        for (int i = 1; i <= n; i ++ ) 
        {
            s[i] = (a[i] >= x ? 1 : -1);
            s[i] += s[i - 1];
        }
        int mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i ++ )
        {
            if (i >= k) mn = min(mn, s[i - k]);
            if (s[i] > mn) return true;
        }
        return false;
    };
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << '\n';
    return 0;
}
