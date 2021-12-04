#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int T;
int n;
int a[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        vector<int> prev(n), nxt(n);
        for (int i = 0; i < n; i ++ )
        {
            prev[i] = (i - 1 + n) % n;
            nxt[i] = (i + 1) % n;
        }
        set<int> to_delete;
        for (int i = 0; i < n; i ++ )
            if (gcd(a[i], a[nxt[i]]) == 1)
                to_delete.insert(i);
        int cur = 0;
        vector<int> res;
        for (int t = 0; t < n && to_delete.size() > 0; t ++ )
        {
            auto it = to_delete.lower_bound(cur);
            if (it == to_delete.end()) it = to_delete.begin();
            int i = *it;
            to_delete.erase(it);
            res.emplace_back(nxt[i]);
            to_delete.erase(nxt[i]);
            nxt[i] = nxt[nxt[i]];
            prev[nxt[i]] = i;
            if (gcd(a[i], a[nxt[i]]) == 1) to_delete.insert(i);
            cur = nxt[i];
        }
        cout << res.size() << ' ';
        for (auto &u : res) cout << u + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
