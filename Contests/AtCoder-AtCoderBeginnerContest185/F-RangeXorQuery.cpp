/**
 * Author: Daniel
 * Created Time: 2020-12-13 21:26:45
**/

// time-limit: 3000
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
const int N = 300010, M = 1010;

int n, m;
int a[N];
int tr[30][N];

void add(int id, int c, int x)
{
    for (int i = c; i <= n; i += lowbit(i)) tr[id][i] += x;
}

int sum(int id, int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[id][i];
    return res;
}

int sum(int id, int l, int r)
{
    return sum(id, r) - sum(id, l - 1);
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        for (int j = 0; j < 30; j ++ )
            if ((a[i] >> j) & 1)
                add(j, i, 1);
    }

    int t, x, y;
    while (m -- )
    {
        cin >> t >> x >> y;
        if (t == 1)
        {
            for (int j = 0; j < 30; j ++ )
                if ((a[x] >> j) & 1)
                    add(j, x, -1);

            a[x] ^= y;
            for (int j = 0; j < 30; j ++ )
                if ((a[x] >> j) & 1)
                    add(j, x, 1);

        }
        else
        {
            int res = 0;
            for (int j = 0; j < 30; j ++ )
                if (sum(j, x, y) % 2)
                    res += (1 << j);
            cout << res << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
