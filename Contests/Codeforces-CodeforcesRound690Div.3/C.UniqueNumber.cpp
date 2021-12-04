/**
 * Author: Daniel
 * Created Time: 2020-12-15 22:45:54
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
const int N = 110, M = 1010, INF = 0x3f3f3f3f;

int T;
int x;
int mina[N];
int st[N];

int get(int x)
{
    int res = 0;
    while (x) res += x % 10, x /= 10;
    return res;
}

void dfs(int n, int cur)
{
    if (n)
    {
        int cnt = get(cur);
        mina[cnt] = min(mina[cnt], cur);
    }
    if (n > 9) return;

    for (int i = 1; i <= 9; i ++ )
        if (!st[i])
        {
            st[i] = true;
            dfs(n + 1, cur * 10 + i);
            st[i] = false;
        }
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(mina, 0x3f, sizeof mina);
    dfs(0, 0);

    cin >> T;
    while (T -- )
    {
        cin >> x;
        if (mina[x] == INF) cout << "-1\n";
        else cout << mina[x] << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
