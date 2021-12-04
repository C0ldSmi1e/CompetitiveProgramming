/**
 * Author: Daniel
 * Created Time: 2020-12-07 19:04:59
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
string t;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> t;

    string s;
    while (SZ(s) < n + 10) s += "110";

    LL res = 0;
    for (int i = 0; i < 3; i ++ )
        if (s.substr(i, n) == t)
            res += (LL)1e10 - (n + i - 1) / 3LL;
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
