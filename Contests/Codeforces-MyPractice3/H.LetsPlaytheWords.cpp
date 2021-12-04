#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        set<string> S01, S10;
        map<string, int> mp01, mp10;
        int cnt00 = 0, cnt11 = 0;
        for (int i = 0; i < n; i ++ )
        {
            string s;
            cin >> s;
            char st = s[0], ed = s.back();
            if (st == '0' && ed == '1') S01.insert(s), mp01[s] = i;
            else if (st == '1' && ed == '0') S10.insert(s), mp10[s] = i;
            else if (st == '0') cnt00 ++ ;
            else if (st == '1') cnt11 ++ ;
        }
        if (cnt00 && cnt11 && !S01.size() && !S10.size())
        {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        if ((int)S01.size() < S10.size()) S01.swap(S10), mp01.swap(mp10);
        while ((int)S01.size() - S10.size() > 1)
        {
            string s = *S01.begin();
            string t = s;
            reverse(t.begin(), t.end());
            if (S10.count(t))
            {
                S01.erase(s);
                S10.erase(t);
            }
            else
            {
                res.emplace_back(mp01[s]);
                S01.erase(s);
                S10.insert(t);
            }
        }
        cout << (int)res.size() << '\n';
        for (auto &u : res) cout << u + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
