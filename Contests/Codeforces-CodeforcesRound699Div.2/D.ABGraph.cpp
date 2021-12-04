/**
 * Author: Daniel
 * Created Time: 2021-02-07 11:42:06
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
const int N = 2010, M = 1010;

int T;
int n, m;
char g[N][N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;

        int x = 1, y = 2;
        bool flag = (m & 1);
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j < i; j ++ )
                if (g[i][j] == g[j][i])
                {
                    flag = true;
                    x = i, y = j;
                }

        if (flag)
        {
            cout << "YES\n";
            for (int i = 0; i <= m; i ++ )
                if (i & 1) cout << x << ' ';
                else cout << y << ' ';
            cout << '\n';
        }
        else
        {
            if (n < 3) cout << "NO\n";
            else 
            {
                cout << "YES\n";
                int z = 3;
                for (int i = 1; i <= 3; i ++ )
                    for (int j = 1; j <= 3; j ++ )
                        for (int k = 1; k <= 3; k ++ )
                            if (i != j && j != k && i != k)
                                if (g[i][j] == g[j][k] && g[k][j] == g[j][i])
                                    x = i, y = j, z = k;
                assert(g[x][y] == g[y][z] && g[z][y] == g[y][x]);

                VI t;
                if ((m / 2) & 1)
                {
                    t.EB(x);
                    t.EB(y);
                    t.EB(z);
                    t.EB(y);
                }
                else
                {
                    t.EB(y);
                    t.EB(z);
                    t.EB(y);
                    t.EB(x);
                }
                for (int i = 0; i <= m; i ++ ) cout << t[i % 4] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}

// GOOD LUCK!!!
