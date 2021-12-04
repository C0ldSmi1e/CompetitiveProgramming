/**
* Author: Name
* Created Time: 2020-11-22 22:43:05
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
LL m;
LL a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    VE<LL> f;
    int t = n / 2;
    for (int bit = 0; bit < 1 << t; bit ++ )
    {
        LL sum = 0;
        for (int i = 0; i < t; i ++ )
            if ((bit >> i) & 1)
                sum += a[i];
        if (sum <= m) f.EB(sum);
    }

    sort(ALL(f));

    LL res = f.back();
    for (int bit = 0; bit < 1 << (n - t); bit ++ )
    {
        LL sum = 0;
        for (int i = 0; i < (n - t); i ++ )
            if ((bit >> i) & 1)
                sum += a[i + t];

        if (sum <= m) 
        {
            res = max(res, sum);
            auto it = upper_bound(ALL(f), m - sum);
            if ( -- it != f.begin()) res = max(res, *it + sum);
        }
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
