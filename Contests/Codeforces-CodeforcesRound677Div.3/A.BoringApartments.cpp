/**
*  Author: Daniel
*  Created Time: 2020-10-20 22:37:52
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
int n;

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n;
        int res = 0;
        for (int i = 1; i <= 9; i ++ )
        {
            int c = i;
            bool flag = true;
            for (int j = 1; c <= 9999; j ++ , c = c * 10 + i)
            {
                res += j;
                if (c == n)
                {
                    flag = false;
                    break;
                }
            }

            if (!flag) break;
        }
        cout << res << '\n';
    }
    return 0;
}
