/**
 * Author: Daniel
 * Created Time: 2021-01-26 10:28:14
**/

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
const int N = 100010, M = 1010;

int T;
int n, m;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        VI a(n), b(n);

        LL sum = 0;
        for (auto &u : a) 
        {
            cin >> u;
            sum += u;
        }
        for (auto &u : b) cin >> u;

        if (sum < m)
        {
            cout << "-1\n";
            continue;
        }

        VE<LL> s1, s2;
        for (int i = 0; i < n; i ++ )
            if (b[i] == 1) s1.EB(a[i]);
            else s2.EB(a[i]);

        sort(RALL(s1));
        sort(RALL(s2));

        int res = 0x3f3f3f3f;
        LL cur = 0;
        for (auto &u : s2) cur += u;

        for (int i = SZ(s2), j = 0; i >= 0; i -- )
        {
            while (j < SZ(s1) && cur < m)
            {
                cur += s1[j];
                j ++ ;
            }
            if (cur >= m) res = min(res, 2 * i + j);
            if (i) cur -= s2[i - 1];
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
