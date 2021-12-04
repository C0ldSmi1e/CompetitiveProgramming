/**
 * Author: Daniel
 * Created Time: 2021-01-23 23:28:55
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
const int N = 1010, M = 1010;

int n, cnt;
bool dx[N], ux[N], col[N];
VI path;

void dfs(int u)
{
    if (u >= n)
    {
        cnt ++ ;
        if (cnt <= 3)
        {
            for (auto &u : path) cout << u << ' ';
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= n; i ++ )
        if (!col[i] && !dx[u + i] && !ux[u - i + n])
        {
            col[i] = dx[u + i] = ux[u - i + n] = true;
            path.EB(i);
            dfs(u + 1);
            path.PB();
            col[i] = dx[u + i] = ux[u - i + n] = false;
        }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    dfs(0);
    cout << cnt << '\n';
    return 0;
}

// GOOD LUCK!!!
