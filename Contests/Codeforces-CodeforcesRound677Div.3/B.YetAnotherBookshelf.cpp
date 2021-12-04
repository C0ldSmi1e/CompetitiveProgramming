/**
*  Author: Daniel
*  Created Time: 2020-10-20 22:43:23
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
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        int l, r;
        for (int i = 0; i < n; i ++ )
            if (a[i] == 1)
            {
                l = i;
                break;
            }

        for (int i = n - 1; i >= 0; i -- )
            if (a[i] == 1)
            {
                r = i;
                break;
            }

        int cnt = 0;
        for (int i = l; i <= r; i ++ )
            if (a[i] == 1)
                cnt ++ ;

        cout << r - l + 1 - cnt << '\n';
    }
    return 0;
}
