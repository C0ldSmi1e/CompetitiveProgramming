/**
* Author: Daniel
* Created Time: 2020-11-24 00:57:54
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

int n, a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + 1 + n);

    if (a[n] - a[1] <= 17)
    {
        cout << "0\n";
        return 0;
    }

    int res = 0x3f3f3f3f;
    for (int l = a[1]; l + 17 <= a[n]; l ++ )
    {
        int r = l + 17, sum = 0;
        for (int i = 1; i <= n; i ++ )
            if (a[i] < l) sum += (l - a[i]) * (l - a[i]);
            else if (a[i] > r) sum += (a[i] - r) * (a[i] - r);
        res = min(res, sum);
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
