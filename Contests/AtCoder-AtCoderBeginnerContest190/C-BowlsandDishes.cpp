/**
 * Author: Daniel
 * Created Time: 2021-02-24 13:15:46
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
const int N = 110, M = 1010;

int n, m, k;
bool st[N];
PII con[N], p[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 0; i < m; i ++ ) cin >> con[i].F >> con[i].S;
    cin >> k;
    for (int i = 0; i < k; i ++ ) cin >> p[i].F >> p[i].S;
    int res = 0;
    for (int mask = 0; mask < 1 << k; mask ++ )
    {
        memset(st, 0, sizeof st);
        for (int i = 0; i < k; i ++ )
            if ((mask >> i) & 1) st[p[i].F] = true;
            else st[p[i].S] = true;
        int cnt = 0;
        for (int i = 0; i < m; i ++ )
            if (st[con[i].F] && st[con[i].S])
                cnt ++ ;
        res = max(res, cnt);
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
