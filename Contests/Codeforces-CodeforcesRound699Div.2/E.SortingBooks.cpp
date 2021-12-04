/**
 * Author: Daniel
 * Created Time: 2021-02-08 17:23:35
**/

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
const int N = 500010, M = 1010;

int n;
int a[N];
int l[N], r[N];
int mx[N], cnt[N];
int f[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if (!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
    }
    for (int i = n; i; i -- )
    {
        cnt[a[i]] ++ ;
        mx[i] = max(mx[i + 1], cnt[a[i]]);
    }

    for (int i = 1; i <= n; i ++ )
    {
        f[i] = f[i - 1];
        if (r[a[i]] == i)
            f[i] = max(f[i], cnt[a[i]] + f[l[a[i]] - 1]);
    }

    int maxa = 0;
    for (int i = 0; i <= n; i ++ ) maxa = max(maxa, f[i] + mx[i + 1]);
    cout << n - maxa << '\n';
    return 0;
}

// GOOD LUCK!!!
