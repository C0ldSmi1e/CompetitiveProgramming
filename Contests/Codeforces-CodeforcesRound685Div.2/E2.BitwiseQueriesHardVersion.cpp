/**
* Author: Name
* Created Time: 2020-11-23 00:21:53
**/

// time-limit: 4000
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

int n;
int XOR[N];
VE<int> pos[N];

int ask(string s, int i, int j)
{
    cout << s << ' ' << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int x)
{
    cout << ' ' << x;
    cout.flush();
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    int a = 1, b = -1, c = -1;
    for (int i = 2; i <= n; i ++ )
    {
        XOR[i] = ask("XOR", 1, i);
        pos[XOR[i]].EB(i);
    }

    bool same = false;
    for (int i = 0; i < n; i ++ )
        if (SZ(pos[i]) > 1)
        {
            same = true;
            b = pos[i][0];
            c = pos[i][1];
        }

    int and12 = 0;
    int and13 = 0;
    int and23 = 0;

    if (same)
    {
        and12 = ask("AND", a, b);
        and13 = and12;
        and23 = ask("AND", b, c);
    }
    else
    {
        for (int i = 2; i <= 3; i ++ )
            for (int j = i + 1; j <= n; j ++ )
                if ((XOR[i] ^ XOR[j]) == n - 1)
                    b = i, c = j;
        and12 = ask("AND", a, b);
        and13 = ask("AND", a, c);
    }


    cout << "!";
    cout.flush();

    int a1 = (XOR[b] + 2 * and12 + XOR[c] + 2 * and13 - (XOR[b] ^ XOR[c]) - 2 * and23) / 2;
    answer(a1);
    for (int i = 2; i <= n; i ++ ) answer(a1 ^ XOR[i]);
    return 0;
}

// GOOD LUCK!!!
