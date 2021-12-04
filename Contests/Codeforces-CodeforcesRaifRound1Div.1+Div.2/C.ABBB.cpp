/**
*  Author: Daniel
*  Created Time: 2020-10-17 22:05:05
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
const int N = 200010, M = 1010;

int T;
string s;
char stk[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> s;
        int n = SZ(s);

        int tt = 0, cntB = 0, res = 0;
        for (auto u : s)
            if (u == 'A')
            {
                stk[ ++ tt] = u;
                if (!tt)
                {
                    res += cntB % 2;
                    cntB = 0;
                }
            }
            else
            {
                if (tt) tt -- ;
                else cntB ++ ;
            }
        res += tt + cntB % 2;
        cout << res << '\n';
    }
    return 0;
}
