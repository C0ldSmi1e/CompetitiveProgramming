/**
 * Author: Daniel
 * Created Time: 2021-01-30 10:40:53
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
const int N = 1010, M = 1010, INF = 0x3f3f3f3f;

int n;
int g[N][N];
int s[N][N];
int t[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            cin >> g[i][j];
            s[i][j] = s[i - 1][j] + g[i][j];
        }

    int res = -INF;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
        {
            for (int k = 1; k <= n; k ++ ) t[k] = s[i][k] - s[j - 1][k];

            for (int k = 1, sum = 0, mina = 0; k <= n; k ++ )
            {
                sum += t[k];
                res = max(res, sum - mina);
                mina = min(mina, sum);
            }
        }

    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
