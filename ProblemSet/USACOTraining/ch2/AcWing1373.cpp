/**
 * Author: Daniel
 * Created Time: 2020-12-11 00:20:30
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
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 1010, M = 200010;

int n = 10;
char g[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void move(int &x, int &y, int &t)
{
    int tx = x + dx[t], ty = y + dy[t];
    if (tx < 1 || tx > n || ty < 1 || ty > n || g[tx][ty] == '*') (t += 1) %= 4;
    else x = tx, y = ty;
}

// read the question carefully!!!
int main()
{
    SOS;

    int x1, y1, t1 = 0, x2, y2, t2 = 0;
    for (int i = 1; i <= n; i ++ ) 
    {
        cin >> g[i] + 1;
        for (int j = 1; j <= n; j ++ )
            if (g[i][j] == 'C') x1 = i, y1 = j;
            else if (g[i][j] == 'F') x2 = i, y2 = j;
    }

    for (int i = 1; i < M; i ++ )
    {
        move(x1, y1, t1);
        move(x2, y2, t2);

        if (x1 == x2 && y1 == y2)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}

// GOOD LUCK!!!
