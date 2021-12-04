/**
 * Author: Daniel
 * Created Time: 2021-04-25 12:53:28
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 10, M = 1010;

int n;
bool st[N][N];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int check(int x, int y)
{
    if (x == n && y == 1 || st[x][y]) return 0;
    int cnt = 0;
    for (int i = 0; i < 4; i ++ )
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        cnt += (int)(!st[tx][ty]);
    }
    return (int)(cnt <= 1);
}

int dfs(int x, int y, int k)
{
    st[x][y] = true;
    int res = 0;
    if (x == n && y == 1) res = (int)(k == n * n);
    else if (st[x - 1][y] && st[x + 1][y] && !st[x][y - 1] && !st[x][y + 1] || st[x][y - 1] && st[x][y + 1] && !st[x - 1][y] && !st[x + 1][y]) res = 0;
    else
    {
        int cnt = 0, sx = -1, sy = -1;
        for (int i = 0; i < 4; i ++ )
        {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (check(tx, ty))
            {
                cnt ++ ;
                sx = tx, sy = ty;
            }
        }
        if (cnt > 1) res = 0;
        else if (cnt == 1) res += dfs(sx, sy, k + 1);
        else
        {
            for (int i = 0; i < 4; i ++ )
            {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (!st[tx][ty]) res += dfs(tx, ty, k + 1);
            }
        }
    }
    st[x][y] = false;
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i <= n + 1; i ++ )
        st[i][0] = st[0][i] = st[n + 1][i] = st[i][n + 1] = true;
    cout << dfs(1, 1, 1) << '\n';
    return 0;
}

// GOOD LUCK!!!
