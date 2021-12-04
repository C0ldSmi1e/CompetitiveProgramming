/**
*  Author: Daniel
*  Created Time: 2020-10-20 23:10:23
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

LL n;
LL f[N];
LL fact[N];

LL C(LL a, LL b)
{
    LL res = 1LL;
    for (int i = a, j = 1; j <= b; i -- , j ++ )
        res = res * i / j;
    return res;
}

// read the question carefully!!!
int main()
{
    cin >> n;
    f[2] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n; i ++ ) fact[i] = i * fact[i - 1];
    for (int i = 4; i <= n; i += 2) f[i] = C(i, i / 2) / 2LL * fact[i / 2 - 1] * fact[i / 2 - 1];
    cout << f[n] << '\n';
    return 0;
}
