/**
* Author: Daniel
* Created Time: 2020-11-24 01:03:46
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
#define MT(x, y, z) make_tuple(x, y, z)
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;
typedef tuple<int, int, int> TIII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int n;
int a, b, c;
set<TIII> S;

int add(int x, int c)
{
    return (x + c + n) % n;
}

void op()
{
    cin >> a >> b >> c;
    a %= n, b %= n, c %= n;
    for (int i = -2; i <= 2; i ++ )
        for (int j = -2; j <= 2; j ++ )
            for (int k = -2; k <= 2; k ++ )
            {
                int x = add(a, i), y = add(b, j), z = add(c, k);
                S.IS(MT(x, y, z));
            }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    
    op();
    op();

    cout << SZ(S) << '\n';
    return 0;
}

// GOOD LUCK!!!
