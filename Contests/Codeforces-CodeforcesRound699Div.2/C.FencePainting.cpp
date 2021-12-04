/**
 * Author: Daniel
 * Created Time: 2021-02-08 11:32:09
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
const int N = 100010, M = 1010;

int T;
int n, m;
int a[N], b[N], c[N];
int res[N];
VI need[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ ) 
        {
            res[i] = -1;
            need[i].clear();
        }
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) 
        {
            cin >> b[i];
            if (a[i] != b[i])
                need[b[i]].EB(i);
        }
        for (int i = 1; i <= m; i ++ ) cin >> c[i];

        int last = -1;
        if (SZ(need[c[m]]))
        {
            last = need[c[m]].back();
            need[c[m]].PB();
        }
        else
        {
            for (int i = 1; i <= n; i ++ )
                if (b[i] == c[m])
                    last = i;
        }

        if (last == -1)
        {
            cout << "NO\n";
            continue;
        }
        else res[m] = last;

        for (int i = 1; i <= m - 1; i ++ )
        {
            int now = c[i];
            if (SZ(need[now]))
            {
                res[i] = need[now].back();
                need[now].PB();
            }
            else res[i] = last;
        }

        bool flag = true;
        for (int i = 1; i <= n; i ++ )
            if (SZ(need[i]))
                flag = false;

        if (flag)
        {
            cout << "YES\n";
            for (int i = 1; i <= m; i ++ )
            {
                cout << res[i];
                cout << " \n"[i == m];
            }
        }
        else cout << "NO\n";
    }
    return 0;
}

// GOOD LUCK!!!
