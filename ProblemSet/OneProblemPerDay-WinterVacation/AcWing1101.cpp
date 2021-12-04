/**
 * Author: Daniel
 * Created Time: 2021-02-03 12:36:32
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
const int N = 1010, M = 1010;

int T;
int n, m;
PII q[N * N];
int d[N][N];
char g[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        PII st, ed;
        for (int i = 1; i <= n; i ++ ) 
        {
            cin >> g[i] + 1;
            for (int j = 1; j <= m; j ++ )
            {
                d[i][j] = -1;
                if (g[i][j] == 'S') st = MP(i, j);
                else if (g[i][j] == 'E') ed = MP(i, j);
            }
        }

        int hh = 0, tt = -1;
        q[ ++ tt] = st;
        d[st.F][st.S] = 0;

        while (hh <= tt)
        {
            auto t = q[hh ++ ];
            for (int i = 0; i < 4; i ++ )
            {
                int tx = t.F + dx[i];
                int ty = t.S + dy[i];
                if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
                if (g[tx][ty] == '#' || d[tx][ty] != -1) continue;

                d[tx][ty] = d[t.F][t.S] + 1;
                q[ ++ tt] = MP(tx, ty);
            }
        }

        int res = d[ed.F][ed.S];
        if (res == -1) cout << "oop!\n";
        else cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
