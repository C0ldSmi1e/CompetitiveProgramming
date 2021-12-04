/**
*  Author: Daniel
*  Created Time: 2020-10-24 22:12:56
**/

// time-limit: 1500
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
const int N = 1010, M = 1010;

int T;
int n;
int g[N][N];

bool check(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                g[i][j] = 1;
        
        int p = n + 1;
        while (true)
        {
            if (check(p) && !check(p - n + 1))
                break;
            p ++ ;
        }

        for (int i = 1; i <= n; i ++ ) g[i][i] = p - n + 1;

        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 1; j <= n; j ++ )
                cout << g[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
