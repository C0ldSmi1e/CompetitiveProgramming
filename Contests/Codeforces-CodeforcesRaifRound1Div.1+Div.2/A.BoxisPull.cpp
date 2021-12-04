/**
*  Author: Daniel
*  Created Time: 2020-10-17 21:05:49
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
int x1, Y1, x2, y2;

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> x1 >> Y1 >> x2 >> y2;
        if (x1 == x2 || Y1 == y2)
            cout << abs(x1 - x2) + abs(Y1 - y2) << '\n';
        else
            cout << abs(x1 - x2) + abs(Y1 - y2) + 2 << '\n';
    }
    return 0;
}
