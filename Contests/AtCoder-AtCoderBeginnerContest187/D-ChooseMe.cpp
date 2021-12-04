/**
 * Author: Daniel
 * Created Time: 2021-01-02 20:20:41
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
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
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

int n;
PA<LL, LL> a[N];

bool cmp(PA<LL, LL> a, PA<LL, LL> b)
{
    return a.F + a.S - b.F > b.F + b.S - a.F;
}

bool check(int cnt)
{
    LL sum = 0;
    for (int i = 0; i < cnt; i ++ )
    {
        sum += a[i].F;
        sum += a[i].S;
    }
    
    LL tot = 0;
    for (int i = cnt; i < n; i ++ ) tot += a[i].F;
    return sum > tot;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i].F >> a[i].S;
    sort(a, a + n, cmp);

    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}

// GOOD LUCK!!!
