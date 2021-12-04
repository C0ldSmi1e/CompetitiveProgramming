/**
*  Author: Daniel
*  Created Time: 2020-10-17 21:11:14
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
const int N = 300010, M = 1010;

int T;
int n;
string s;
bool st[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n >> s;

        for (int i = 0; i < n; i ++ ) st[i] = false;

        bool l = false, r = false;
        for (auto u : s)
            if (u == '<') l = true;
            else if (u == '>') r = true;

        int cnt = 0;
        for (int i = 0; i < n; i ++ )
            if (s[i] == '-')
                st[i] = st[(i + 1) % n] = true;

        int res = 0;
        for (int i = 0; i < n; i ++ )
            if (st[i])
                res ++ ;

         if (l && r) cout << res << '\n';       
         else cout << n << '\n';
    }
    return 0;
}
