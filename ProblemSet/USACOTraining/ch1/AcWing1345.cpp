/**
* Author: Daniel
* Created Time: 2020-11-23 13:33:18
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
#define SZ(x) (int)(x.size())
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
const int N = 110, M = 1010;

char a[N][N] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
string s, num;
set<string> S;
VE<string> res;

void dfs(int u, string cur)
{
    if (u >= SZ(num))
    {
        if (S.find(cur) != S.end()) res.EB(cur);
        return;
    }

    int x = num[u] - '0';
    for (int i = 0; i < 3; i ++ )
    {
        string t = cur;
        t += a[x][i];
        dfs(u + 1, t);
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> num;
    while (cin >> s) S.IS(s);

    dfs(0, "");

    sort(ALL(res));
    for (auto &u : res) cout << u << '\n';
    return 0;
}

// GOOD LUCK!!!
