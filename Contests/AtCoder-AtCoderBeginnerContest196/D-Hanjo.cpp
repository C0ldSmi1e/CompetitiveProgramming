/**
 * Author: Daniel
 * Created Time: 2021-03-20 20:56:54
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
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
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
const int N = 110, M = 1010;

int n, m, a, b;
set<ULL> S;
int res;
bool st[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int u, ULL HASH)
{
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cout << st[i][j] << " \n"[j == m];
    cout << '\n';
    if (u >= a)
    {
        if (!S.count(HASH))
        {
            S.IS(HASH);
            res ++ ;
        }
        return;
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (!st[i][j])
                for (int k = 0; k < 4; k ++ )
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
                    if (st[tx][ty]) continue;
                    st[i][j] = st[tx][ty] = true;
                    HASH += (i * n + j) * (tx * n + ty);
                    dfs(u + 1, HASH);
                    HASH -= (i * n + j) * (tx * n + ty);
                    st[i][j] = st[tx][ty] = false;
                }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m >> a >> b;
    dfs(0, 0);
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
