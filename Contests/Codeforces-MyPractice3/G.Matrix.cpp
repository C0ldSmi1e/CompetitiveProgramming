#include <map>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int x;
    string s;
    cin >> x >> s;
    int n = (int)s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) a[i] = s[i] - '0';
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i ++ ) sum[i + 1] = sum[i] + a[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < i; j ++ )
            mp[sum[i] - sum[j]] ++ ;
    long long res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < i; j ++ )
        {
            int d = sum[i] - sum[j];
            if (x)
            {
                if (d && x % d == 0) res += mp[x / d];
            }
            else
            {
                if (d == 0) res += (long long)(n + 1) * n / 2;
                else res += mp[0];
            }
        }
    cout << res << '\n';
    return 0;
}
