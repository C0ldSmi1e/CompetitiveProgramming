/**
 * Author: Daniel
 * Created Time: 2020-12-07 13:47:05
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
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
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 300010, M = 19;

int T;
int n, a[N];
int cnt[N];
int f[N][M];
int LOG2[N];

void init()
{
    for (int j = 0; j < M; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            if (!j) f[i][j] = a[i];
            else f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

bool check()
{
    for (int i = 1; i <= n; i ++ ) cnt[i] = 0;
    for (int i = 1; i <= n; i ++ ) cnt[a[i]] ++ ;
    for (int i = 1; i <= n; i ++ )
        if (!cnt[i])
            return false;
    return true;
}

int query(int l, int r)
{
    int len = r - l + 1;
    int k = LOG2[len];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 2; i < N; i ++ ) LOG2[i] = LOG2[i / 2] + 1;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        init();

        string res;
        int l = 1, r = n, cur = 1;

        while (l < r)
        {
            int mina = query(l, r);
            if (mina == cur)
            {
                res += "1";
                if (a[l] == cur) l ++ ;
                else if (a[r] == cur) r -- ;
                cur ++ ;
            }
            else
            {
                while (SZ(res) < n - 1) res += "0";
                break;
            }
        }

        if (check()) res += "1";
        else res += "0";

        reverse(ALL(res));
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
