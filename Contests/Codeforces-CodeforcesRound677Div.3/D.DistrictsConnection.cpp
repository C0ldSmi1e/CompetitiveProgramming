/**
*  Author: Daniel
*  Created Time: 2020-10-20 22:59:24
**/

// time-limit: 1000
#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define SZ(x) (int)x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 100010, M = 1010;

int T;
int n, a[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        bool same = true;
        for (int i = 2; i <= n; i ++ )
            if (a[i] != a[i - 1])
                same = false;

        if (same)
        {
            cout << "NO\n";
            continue;
        }
        else cout << "YES\n";

        int idx;
        bool flag = false;
        for (int i = 2; i <= n; i ++ )
            if (a[i] != a[1]) 
            {
                idx = i;
                cout << 1 << ' ' << i << '\n';
            }
            else flag = true;

        if (flag)
        {
            for (int i = 2; i <= n; i ++ )
                if (a[i] == a[1])
                    cout << idx << ' ' << i << '\n';
        }
    }
    return 0;
}
