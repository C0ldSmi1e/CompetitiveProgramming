/**
 * Author: Daniel
 * Created Time: 2021-01-04 23:01:32
**/

// time-limit: 2000
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
const int N = 200010, M = 1010;

int T;
int n, a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        VI odd, even;
        for (int i = 0; i < n; i ++ )
        {
            cin >> a[i];
            if (a[i] & 1) odd.EB(a[i]);
            else even.EB(a[i]);
        }

        sort(ALL(odd));
        sort(ALL(even));

        int t = 0;
        LL ali = 0, bob = 0;
        while (true)
        {
            if (!SZ(even) && !SZ(odd)) break;

            if (!t)
            {
                if (SZ(odd) && SZ(even))
                {
                    if (even.back() > odd.back())
                    {
                        ali += even.back();
                        even.PB();
                    }
                    else odd.PB();
                }
                else if (SZ(even))
                {
                    ali += even.back();
                    even.PB();
                }
                else odd.PB();
            }
            else
            {
                if (SZ(odd) && SZ(even))
                {
                    if (even.back() < odd.back())
                    {
                        bob += odd.back();
                        odd.PB();
                    }
                    else even.PB();
                }
                else if (SZ(odd))
                {
                    bob += odd.back();
                    odd.PB();
                }
                else even.PB();
            }
            t ^= 1;
        }

        if (ali == bob) cout << "Tie\n";
        else if (ali > bob) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}

// GOOD LUCK!!!
