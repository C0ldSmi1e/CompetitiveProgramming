/**
* Author: Daniel
* Created Time: 2020-11-23 22:27:04
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
const int N = 100010, M = 1000010;

int A, B, C;
set<int> S;
tuple<int, int, int> q[M];
set<tuple<int, int, int> > st;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> A >> B >> C;
    tuple<int, int, int> start = {0, 0, C}, nxt;

    int hh = 0, tt = -1;
    q[ ++ tt] = start;
    st.IS(start);
    S.IS(C);

    int a, b, c, v;
    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        tie(a, b, c) = t;

        // 6 choices
        // 1: A to B, 2: A to C
        // 3: B to A, 4: B to C
        // 5: C to A, 6: C to B
        for (int i = 1; i <= 6; i ++ )
        {
            tie(a, b, c) = t;
            if (i == 1)
            {
                if (!a) continue;
                v = min(a, B - b);
                a -= v, b += v;
            }
            else if (i == 2)
            {
                if (!a) continue;
                v = min(a, C - c);
                a -= v, c += v;
            }
            else if (i == 3)
            {
                if (!b) continue;
                v = min(b, A - a);
                b -= v, a += v;
            }
            else if (i == 4)
            {
                if (!b) continue;
                v = min(b, C - c);
                b -= v, c += v;
            }
            else if (i == 5)
            {
                if (!c) continue;
                v = min(c, A - a);
                c -= v, a += v;
            }
            else if (i == 6)
            {
                if (!c) continue;
                v = min(c, B - b);
                c -= v, b += v;
            }

            nxt = make_tuple(a, b, c);
            if (st.find(nxt) == st.end())
            {
                st.IS(nxt);
                if (!a) S.IS(c);
                q[ ++ tt] = nxt;
            }
        }
    }

    for (auto &u : S) cout << u << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
