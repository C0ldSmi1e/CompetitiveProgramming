#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> S;
    for (auto &u : a)
    {
        cin >> u;
        S.insert(u);
    }
    sort(a.begin(), a.end());
    multiset<int> seg;
    int sum = 0;
    for (int i = 1; i < n; i ++ ) 
    {
        sum += a[i] - a[i - 1];
        seg.insert(a[i] - a[i - 1]);
    }
    while (q -- )
    {
        int t, x;
        cin >> t >> x;
        if ((int)seg.size() == 0) cout << "0\n";
        else cout << sum - *prev(seg.end()) << '\n';
        if (t == 0)
        {
            auto it = S.find(x);
            auto lit = prev(it), rit = next(it);
            if (it != S.begin()) seg.erase(seg.find(*it - *lit)), sum -= (*it - *lit);
            if (rit != S.end()) seg.erase(seg.find(*rit - *it)), sum -= (*rit - *it);
            if (it != S.begin() && rit != S.end()) seg.insert(*rit - *lit), sum += (*rit - *lit);
            S.erase(it);
        }
        else
        {
            S.insert(x);
            auto it = S.find(x);
            auto lit = prev(it), rit = next(it);
            if (it != S.begin()) seg.insert(*it - *lit), sum += (*it - *lit);
            if (rit != S.end()) seg.insert(*rit - *it), sum += (*rit - *it);
            if (it != S.begin() && rit != S.end()) seg.erase(seg.find(*rit - *lit)), sum -= (*rit - *lit);
        }
    }
    if ((int)seg.size() == 0) cout << "0\n";
    else cout << sum - *prev(seg.end()) << '\n';
    return 0;
}
