#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int res = 0;
    for (int bit = 0; bit < 25; bit ++ )
    {
        vector<int> b(a);
        for (auto &u : b) u %= (1 << (bit + 1));
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int i = 0; i < n; i ++ )
        {
            // [2^bit, 2^(bit+1)-1]
            {
                int L = (1 << bit);
                int R = (1 << (bit + 1)) - 1;
                int l = lower_bound(b.begin(), b.end(), L - b[i]) - b.begin();
                int r = upper_bound(b.begin(), b.end(), R - b[i]) - b.begin() - 1;
                cnt += (r - l + 1);
                cnt -= (i >= l && i <= r);
            }
            // [2^bit+2^(bit+1), 2^(bit+2)-1]
            {
                int L = (1 << bit) + (1 << (bit + 1));
                int R = (1 << (bit + 2)) - 1;
                int l = lower_bound(b.begin(), b.end(), L - b[i]) - b.begin();
                int r = upper_bound(b.begin(), b.end(), R - b[i]) - b.begin() - 1;
                cnt += (r - l + 1);
                cnt -= (i >= l && i <= r);
            }
        }
        cnt /= 2;
        if (cnt & 1) res |= (1 << bit);
    }
    cout << res << '\n';
    return 0;
}
