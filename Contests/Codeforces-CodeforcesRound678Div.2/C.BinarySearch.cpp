/**
*  Author: Daniel
*  Created Time: 2020-10-29 00:44:38
**/

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
const int N = 1010, M = 1010, mod = 1e9 + 7;

int n, x, pos;
int C[N][N];
int fact[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> x >> pos;

    fact[0] = 1;
    for (int i = 1; i < N; i ++ ) fact[i] = (LL)fact[i - 1] * i % mod;
    
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;

    int small = 0, big = 0;
    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (mid <= pos)
        {
            if (mid < pos) small ++ ;
            l = mid + 1;
        }
        else
        {
            r = mid;
            big ++ ;
        }
    }

    int res = (LL)C[n - x][big] * fact[big] % mod;
    res = (LL)res * C[x - 1][small] % mod * fact[small] % mod;
    res = (LL)res * fact[n - big - small - 1] % mod;
    cout << res << '\n';
    return 0;
}

