/**
 * Author: Daniel
 * Created Time: 2021-01-27 14:46:44
**/

// time-limit: 1000
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
typedef vector<LL> VL;
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
const int N = 100010, M = 1010;

int T;
int n;
int p[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) p[i] = i;

        LL tot = 0;
        VE<PII> res;

        res.EB(1, n);
        swap(p[1], p[n]);
        tot += (1 - n) * (LL)(1 - n);

        int i = 2, j = n - 1;
        while (i <= j)
        {
            res.EB(i, n);
            swap(p[n], p[i]);
            tot += (n - i) * (LL)(n - i);
            if (i != j)
            {
                res.EB(j, 1);
                swap(p[1], p[j]);
                tot += (1 - j) * (LL)(1 - j);
            }
            i ++ , j -- ;
        }

        cout << tot << '\n';
        for (int i = 1; i <= n; i ++ )
        {
            cout << p[i];
            cout << " \n"[i == n];
        }
        cout << SZ(res) << '\n';
        reverse(ALL(res));
        for (auto [x, y] : res) cout << x << ' ' << y << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
