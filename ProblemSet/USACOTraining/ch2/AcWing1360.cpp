/**
 * Author: Daniel
 * Created Time: 2020-12-02 13:59:44
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
const int N = 100010, M = 1010;

int n;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

bool cmp(PII a, PII b)
{
    return (double)a.F * b.S < (double)a.S * b.F;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;

    VE<PII> res;
    for (int down = 1; down <= n; down ++ )
        for (int up = 0; up <= down; up ++ )
            if (gcd(up, down) == 1)
                res.EB(MP(up, down));

    sort(ALL(res), cmp);
    for (auto [x, y] : res) cout << x << '/' << y << '\n';
    return 0;
}

// GOOD LUCK!!!
