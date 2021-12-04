/**
 * Author: Daniel
 * Created Time: 2021-01-30 10:55:44
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
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

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
const int N = 100010, M = 1010;

int n;
int a[N];
int son[N * 32][2], id[N *  32], idx;

void insert(int x, int k)
{
    int p = 0;
    for (int i = 31; i >= 0; i -- )
    {
        int u = (x >> i) & 1;
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    id[p] = k;
}

int find(int x)
{
    int p = 0;
    for (int i = 31; i >= 0; i -- )
    {
        int u = (x >> i) & 1;
        if (son[p][u ^ 1]) p = son[p][u ^ 1];
        else p = son[p][u];
    }
    return id[p];
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    insert(0, 0);
    int res = -1, l, r;
    for (int i = 1; i <= n; i ++ )
    {
        int k = find(a[i]);
        int t = a[k] ^ a[i];
        if (t > res)
        {
            res = t;
            l = k + 1, r = i;
        }
        insert(a[i], i);
    }
    cout << res << ' ' << l << ' ' << r << '\n';
    return 0;
}

// GOOD LUCK!!!
