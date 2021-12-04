/**
 * Author: Daniel
 * Created Time: 2020-12-27 16:43:06
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
const int N = 10, M = 1010;

int s, b;
int f[N][N][N][N][N];
int id;
map<int, int> h;

int get(int u)
{
    if (!h.count(u)) h[u] = id ++ ;
    return h[u];
}

void update(VI &v, int p)
{
    for (int a = v[0]; a < 6; a ++ )
        for (int b = v[1]; b < 6; b ++ )
            for (int c = v[2]; c < 6; c ++ )
                for (int d = v[3]; d < 6; d ++ )
                    for (int e = v[4]; e < 6; e ++ )
                        f[a][b][c][d][e] = min(f[a][b][c][d][e], f[a - v[0]][b - v[1]][c - v[2]][d - v[3]][e - v[4]] + p);
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(f, 0x3f, sizeof f);
    f[0][0][0][0][0] = 0;

    cin >> s;
    while (s -- )
    {
        int n, c, k, p;
        cin >> n;

        VI v(5, 0);
        while (n -- )
        {
            cin >> c >> k;
            v[get(c)] = k;
        }
        cin >> p;
        update(v, p);
    }

    cin >> b;
    VI need(5, 0);
    while (b -- )
    {
        int c, k, p;
        cin >> c >> k >> p;

        VI v(5, 0);
        need[get(c)] = k;
        v[get(c)] = 1;
        update(v, p);
    }

    cout << f[need[0]][need[1]][need[2]][need[3]][need[4]] << '\n';
    return 0;
}

// GOOD LUCK!!!
