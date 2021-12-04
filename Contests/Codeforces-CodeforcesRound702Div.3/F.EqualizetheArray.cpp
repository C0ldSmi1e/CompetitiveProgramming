/**
 * Author: Daniel
 * Created Time: 2021-02-17 00:01:13
**/

// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 1010;

int T;
int n, a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i ++ )
        {
            cin >> a[i];
            mp[a[i]] ++ ;
        }

        VE<PII> q;
        for (auto [x, y] : mp) q.EB(MP(y, x));
        sort(ALL(q));

        LL res = 4e18, to_zero = 0;
        for (int i = 0; i < SZ(q); i ++ )
        {
            int j = i;
            while (j < SZ(q) && q[i].S == q[j].S) j ++ ;
            res = min(res, to_zero + (LL)n - (SZ(q) - i) * (LL)q[i].F);
            n -= (j - i) * q[i].F;
            to_zero += (j - i) * q[i].F;
            i = j - 1;
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
