/**
* Author: Daniel
* Created Time: 2020-11-24 01:22:23
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int n;
bool st[N];

bool check(int x, int l, int r)
{
    if (x < l || x > r) return false;
    while (x)
    {
        if (!st[x % 10]) return false;
        x /= 10;
    }
    return true;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        st[x] = true;
    }

    int res = 0;
    for (int i = 1; i <= 999; i ++ )
        for (int j = 1; j <= 99; j ++ )
        {
            if (!check(i, 100, 999) || !check(j, 10, 99)) continue;
            if (!check(i * (j % 10), 100, 999)) continue;
            if (!check(i * (j / 10), 100, 999)) continue;
            if (!check(i * j, 1000, 9999)) continue;

            res ++ ;
        }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
