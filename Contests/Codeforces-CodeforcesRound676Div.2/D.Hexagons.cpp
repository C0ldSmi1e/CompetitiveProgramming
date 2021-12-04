/**
*  Author: Daniel
*  Created Time: 2020-10-24 16:17:03
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
const int N = 100010, M = 1010;

int T;
LL x, y;
LL c1, c2, c3, c4, c5, c6;

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> x >> y;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        LL res = 4e18;
        if (x > 0)
        {
            res = x * c6;
            if (y > 0) res += y * c2;
            else res += -y * c5;

            LL t = x * c1;
            if (y > x) t += (y - x) * c2;
            else t += (x - y) * c5;

            res = min(res, t);
        }
        else
        {
            res = -x * c3;
            if (y > 0) res += y * c2;
            else res += -y * c5;

            LL t = -x * c4;
            if (y > x) t += (y - x) * c2;
            else t += (x - y) * c5;

            res = min(res, t);
        }

        if (x >= y)
        {
            LL t = c6 * (x - y);
            if (y >= 0) t += y * c1;
            else t += -y * c4;

            res = min(res, t);
        }
        else
        {
            LL t = c3 * (y - x);
            if (y >= 0) t += c1 * y;
            else t += c4 * -y;

            res = min(res, t);
        }

        cout << res << '\n';
    }
    return 0;
}
