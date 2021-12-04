/**
 * Author: Daniel
 * Created Time: 2020-12-04 21:27:32
**/

// time-limit: 3000
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
const int N = 2010, M = 1010;

int T;
int n;
char g[N][N];

bool cmp(PII a, PII b)
{
    return a.S < b.S;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;

        VE<PII> p[10];
        for (int i = 1; i <= n; i ++ ) 
        {
            cin >> g[i] + 1;
            for (int j = 1; j <= n; j ++ )
            {
                int d = g[i][j] - '0';
                p[d].EB(MP(i, j));
            }
        }

        VE<int> res(10, 0);
        for (int d = 0; d <= 9; d ++ )
        {
            int &t = res[d];

            sort(ALL(p[d]));
            for (int i = 0; i < SZ(p[d]); i ++ )
            {
                auto a = p[d][i];
                t = max(t, (a.S - 1) * (p[d].back().F - a.F));
                t = max(t, (a.S - 1) * (a.F - p[d].front().F));
                t = max(t, (n - a.S) * (p[d].back().F - a.F));
                t = max(t, (n - a.S) * (a.F - p[d].front().F));
            }
            sort(ALL(p[d]), cmp);
            for (int i = 0; i < SZ(p[d]); i ++ )
            {
                auto a = p[d][i];
                t = max(t, (a.F - 1) * (p[d].back().S - a.S));
                t = max(t, (a.F - 1) * (a.S - p[d].front().S));
                t = max(t, (n - a.F) * (p[d].back().S - a.S));
                t = max(t, (n - a.F) * (a.S - p[d].front().S));
            }
        }

        for (int i = 0; i < 10; i ++ )
        {
            cout << res[i];
            if (i == 9) cout << '\n';
            else cout << ' ';
        }
    }
    return 0;
}

// GOOD LUCK!!!
