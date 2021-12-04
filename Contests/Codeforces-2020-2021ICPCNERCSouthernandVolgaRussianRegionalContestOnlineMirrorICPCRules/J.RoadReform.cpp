/**
 * Author: Daniel
 * Created Time: 2021-01-03 22:37:47
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
const int N = 200010, M = 2 * N;
const LL INF = 4e18;

int T;
int n, m, k;
int p[N];
struct Edge
{
    int a, b, c;
    bool operator<(const Edge &t) const
    {
        return c < t.c;
    }
} e[M];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m >> k;
        for (int i = 0; i <= n; i ++ ) p[i] = i;
        for (int i = 0; i < m; i ++ )
        {
            int a, b, c, cost;
            cin >> a >> b >> c;
            e[i] = {a, b, c};
        }

        sort(e, e + m);

        LL res = 0;
        for (int i = 0; i < m; i ++ )
        {
            int pa = find(e[i].a), pb = find(e[i].b);
            if (pa != pb)
            {
                res += max(0, e[i].c - k);
                p[pa] = pb;
            }
        }

        if (res == 0)
        {
            res = INF;
            for (int i = 0; i < m; i ++ )
                res = min(res, (LL)abs(k - e[i].c));
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
