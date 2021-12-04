#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (auto &u : a) scanf("%d", &u);
    vector<int> b(m);
    for (auto &u : b) scanf("%d", &u);
    auto check = [&](int x) -> bool
    {
        int cnt = 0;
        for (auto &u : a) cnt += (u <= x);
        for (auto &u : b)
            if (u < 0) cnt -= (-u <= cnt);
            else cnt += (u <= x);
        return cnt > 0;
    };
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (!check(r)) puts("0");
    else printf("%d\n", r);
    return 0;
}
