/**
* Author: Name
* Created Time: 2020-11-23 12:34:40
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
const int N = 100010, M = 1010;

int l, r;
set<LL> S;

bool is_prime(LL x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

void op(string &s)
{
    LL x = 0;
    for (auto &u : s) x = x * 10LL + (LL)(u - '0');

    LL t = x, tt = x;
    while (t)
    {
        x = x * 10 + t % 10;
        t /= 10;
    }
    S.IS(x);

    x = tt, t = x / 10;
    while (t)
    {
        x = x * 10 + t % 10;
        t /= 10;
    }
    S.IS(x);
}

// read the question carefully!!!
int main()
{
    SOS;

    for (char a = '0'; a <= '9'; a ++ )
        for (char b = '0'; b <= '9'; b ++ )
            for (char c = '0'; c <= '9'; c ++ )
                for (char d = '0'; d <= '9'; d ++ )
                    for (char e = '0'; e <= '9'; e ++ )
                    {
                        string s;
                        s += a, s += b, s += c, s += d, s += e;
                        op(s);
                    }

    cin >> l >> r;
    for (auto &u : S)
        if (u >= l && u <= r && is_prime(u))
            cout << u << '\n';
    return 0;
}

// GOOD LUCK!!!
