#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> f(n);
    vector<char> q;
    f[0] = 1;
    q.emplace_back(s[0]);
    for (int i = 1; i < n; i ++ )
    {
        int l = 0, r = q.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (s[i] >= q[mid]) r = mid;
            else l = mid + 1;
        }
        if (s[i] >= q[r])
        {
            f[i] = r + 1;
            q[r] = s[i];
        }
        else
        {
            f[i] = q.size() + 1;
            q.emplace_back(s[i]);
        }
    }
    int res = *max_element(f.begin(), f.end());
    cout << res << '\n';
    for (auto &u : f) cout << u << ' ';
    cout << '\n';
    return 0;
}
