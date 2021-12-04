/**
*  Author: Daniel
*  Created Time: 2020-10-24 15:19:20
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
const int N = 500010, M = 1010;

int n, a[N];
int g[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    LL res = 0, cur = 0;
    for (int i = 1; i <= n; i ++ )
        if (!a[i]) res += cur;
        else
        {
            int l = i, r = i;
            while (r <= n && a[r + 1] == 1) r ++ ;
            for (int h = 1; h <= r - l + 1; h ++ )
            {
                cur += l + h - 1 - g[h];
                res += cur;
                g[h] = r - h + 1;
            }
            i = r;
        }
    cout << res << '\n';
    return 0;
}
