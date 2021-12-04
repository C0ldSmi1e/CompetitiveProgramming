/**
 * Author: Daniel
 * Created Time: 2021-02-01 22:55:25
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
const int N = 10, M = 1010;

char g[N][N];
bool row[N][N], col[N][N], cell[N][N][N];

bool dfs(int x, int y)
{
    if (y >= 9) return dfs(x + 1, 0);
    if (x >= 9)
    {
        for (int i = 0; i < 9; i ++ ) cout << g[i] << '\n';
        return true;
    }

    if (g[x][y] != '.') return dfs(x, y + 1);
    for (int i = 1; i <= 9; i ++ )
        if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i])
        {
            row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
            g[x][y] = (char)(i + '0');
            if (dfs(x, y + 1)) return true;
            g[x][y] = '.';
            row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
        }
    return false;
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < 9; i ++ )
    {
        cin >> g[i];
        for (int j = 0; j < 9; j ++ )
            if (g[i][j] != '.')
            {
                int t = (int)(g[i][j] - '0');
                row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
            }
    }
    dfs(0, 0);
    return 0;
}

// GOOD LUCK!!!
