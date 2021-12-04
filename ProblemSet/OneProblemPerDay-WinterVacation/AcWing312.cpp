/**
 * Author: Daniel
 * Created Time: 2021-02-09 14:23:31
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
const int N = 400, M = 41;

int n, m;
int w[N], b[N];
int f[M][M][M][M];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    VI cnt(5);
    for (int i = 1; i <= m; i ++ ) 
    {
        cin >> b[i];
        cnt[b[i]] ++ ;
    }

    memset(f, -1, sizeof f);
    f[0][0][0][0] = w[1];

    int res = 0;
        for (int a = 0; a <= cnt[1]; a ++ )
            for (int b = 0; b <= cnt[2]; b ++ )
                for (int c = 0; c <= cnt[3]; c ++ )
                    for (int d = 0; d <= cnt[4]; d ++ )
                    {
                        int t = f[a][b][c][d];
                        if (t == -1) continue;
                        int cur = 1 + a * 1 + b * 2 + c * 3 + d * 4;
                        if (a < cnt[1]) f[a + 1][b][c][d] = max(f[a + 1][b][c][d], t + w[cur + 1]);
                        if (b < cnt[2]) f[a][b + 1][c][d] = max(f[a][b + 1][c][d], t + w[cur + 2]);
                        if (c < cnt[3]) f[a][b][c + 1][d] = max(f[a][b][c + 1][d], t + w[cur + 3]);
                        if (d < cnt[4]) f[a][b][c][d + 1] = max(f[a][b][c][d + 1], t + w[cur + 4]);
                        if (cur == n) res = max(res, t);
                    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
