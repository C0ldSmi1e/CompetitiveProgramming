/**
* Author: Name
* Created Time: 2020-11-23 10:32:53
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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;

int n;
PII seg[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> seg[i].F >> seg[i].S;

    sort(seg, seg + n);

    int res = seq[0].S - seq[0].F, ans = 0;
    int l = -INF, r = -INF;
    for (int i = 0; i < n; i ++ )
        if (seg[i].F > r)
        {
            if (r != -INF) ans = max(ans, seg[i].F - r);
            l = seg[i].F;
            r = seg[i].S;
        }
        else
        {
            r = max(r, seg[i].S);
            res = max(res, r - l);
        }

    cout << res << ' ' << ans << '\n';
    return 0;
}

// GOOD LUCK!!!
