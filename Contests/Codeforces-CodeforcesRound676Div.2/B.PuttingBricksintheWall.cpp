/**
*  Author: Daniel
*  Created Time: 2020-10-19 22:40:34
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
const int N = 210, M = 1010;

int T;
int n;
char g[N][N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> g[i];

        bool flag = true;
        for (char i = '0'; flag && i <= '1'; i ++ )
            for (char j = '0'; flag && j <= '1'; j ++ )
                if (i != j)
                {
                    int cnt = 0;
                    if (i != g[0][1]) cnt ++ ;
                    if (i != g[1][0]) cnt ++ ;
                    if (j != g[1][1]) cnt ++ ;
                    if (j != g[2][0]) cnt ++ ;
                    if (j != g[0][2]) cnt ++ ;

                    if (cnt <= 2)
                    {
                        flag = false;
                        cout << cnt << '\n';
                        
                        if (i != g[0][1]) cout << "1 2\n";
                        if (i != g[1][0]) cout << "2 1\n";
                        if (j != g[1][1]) cout << "2 2\n";
                        if (j != g[2][0]) cout << "3 1\n";
                        if (j != g[0][2]) cout << "1 3\n";
                    }
                }
    }
    return 0;
}
