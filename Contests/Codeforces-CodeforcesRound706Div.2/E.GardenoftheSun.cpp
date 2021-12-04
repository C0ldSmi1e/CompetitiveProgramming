/**
 * Author: Daniel
 * Created Time: 2021-03-12 17:01:36
**/

// time-limit: 1000
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
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef vector<pair<int, int> > VPII;

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
const int N = 100010, M = 1010;



// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    while (T -- )
    {
        int n, m;
        cin >> n >> m;
        VE<string> g(n);
        for (auto &s : g) cin >> s;
        for (int i = 0; i < n; i += 3) g[i] = string(m, 'X');
        for (int i = 0; i < n; i += 3)
        {
            bool flag = false;
            for (int j = 0; j < m; j ++ )
            {
                bool ok = false;
                if (i + 1 < n && g[i + 1][j] == 'X') ok = true;
                if (i + 2 < n && g[i + 2][j] == 'X') ok = true;
                if (ok)
                {
                    flag = true;
                    if (i + 1 < n) g[i + 1][j] = 'X';
                    if (i + 2 < n) g[i + 2][j] = 'X';
                    break;
                }
            }
            if (!flag)
            {
                if (i + 1 < n) g[i + 1][0] = 'X';
                if (i + 2 < n) g[i + 2][0] = 'X';
            }
        }
        if (n % 3 == 0)
        {
            for (int j = 0; j < m; j ++ )
                if (g[n - 1][j] == 'X')
                    g[n - 2][j] = 'X';
        }
        for (auto &s : g) cout << s << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
