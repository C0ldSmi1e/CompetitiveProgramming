/**
*  Author: Daniel
*  Created Time: 2020-10-20 22:51:16
**/

// time-limit: 2000
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
const int N = 300010, M = 1010;

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
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        bool same = true;
        for (int i = 1; i < n; i ++ )
            if (a[i] != a[i - 1])
                same = false;
        
        if (same)
        {
            cout << "-1\n";
            continue;
        }

        int maxa = 0, idx;
        for (int i = 0; i < n; i ++ ) maxa = max(maxa, a[i]);

        for (int i = 0; i < n; i ++ )
            if (a[i] == maxa && ((i && a[i] > a[i - 1]) || (i < n - 1 && a[i] > a[i + 1])))
            {
                idx = i;
                break;
            }

        cout << idx + 1 << '\n';
    }
    return 0;
}
