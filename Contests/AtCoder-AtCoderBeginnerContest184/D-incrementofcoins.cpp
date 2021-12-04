/**
* Author: Name
* Created Time: 2020-11-22 20:14:07
**/

// time-limit: 2000
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
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(9);

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

int a, b, c;
double f[N][N][N];
bool st[N][N][N];

double dfs(int a, int b, int c)
{
    if (a == 100 || b == 100 || c == 100) return f[a][b][c] = 0;
    if (st[a][b][c]) return f[a][b][c];
    st[a][b][c] = true;

    f[a][b][c] = 1;
    f[a][b][c] += (double)a / (a + b + c) * dfs(a + 1, b, c);
    f[a][b][c] += (double)b / (a + b + c) * dfs(a, b + 1, c);
    f[a][b][c] += (double)c / (a + b + c) * dfs(a, b, c + 1);
    return f[a][b][c];
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> a >> b >> c;
    cout << dfs(a, b, c) << '\n';
    return 0;
}

// GOOD LUCK!!!
