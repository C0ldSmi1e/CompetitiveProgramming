/**
 * Author: Daniel
 * Created Time: 2021-01-30 16:32:26
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
const int N = 3010, M = 1010;

int n, m, k;
int h[N][N];
int top;
bool g[N][N];
struct Rec
{
    LL h, w;
} stk[N];

LL get(int idx)
{
    top = 0;
    LL res = 0;
    for (int i = 1; i <= m + 1; i ++ )
    {
        int height = 0, width = 0;

        if (i == m + 1) height = 0;
        else height = h[idx][i];

        while (top && stk[top].h >= height)
        {
            width += stk[top].w;
            res = max(res, width * stk[top].h);
            top -- ;
        }
        stk[ ++ top] = {height, width + 1};
    }
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m >> k;
    for (int i = 0; i < k; i ++ )
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (g[i][j]) h[i][j] = 0;
            else h[i][j] = h[i - 1][j] + 1;

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, get(i));
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
