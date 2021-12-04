/**
 * Author: Daniel
 * Created Time: 2021-01-26 22:40:43
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
const int N = 200010, M = 1010;

int T;
int n;
int a[N];
int l[N], r[N];

bool check(VI t)
{
    for (int i = 0; i < 3; i ++ )
        if (t[i + 1] < t[i]) return false;
        else t[i + 1] -= t[i];
    return t.back() == 0;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        a[0] = a[n + 1] = 0;
        l[0] = l[n + 1] = 0;
        r[0] = r[n + 1] = 0;
        
        {
            int t = 0;
            for (int i = 1; i <= n; i ++ )
            {
                t = a[i] - t;
                l[i] = t;
            }
            for (int i = 1; i <= n; i ++ )
                if (l[i] < 0 || l[i - 1] == -1)
                    l[i] = -1;
        }

        {
            int t = 0;
            for (int i = n; i; i -- )
            {
                t = a[i] - t;
                r[i] = t;
            }
            for (int i = n; i; i -- )
                if (r[i] < 0 || r[i + 1] == -1)
                    r[i] = -1;
        }

        bool flag = false;
        for (int i = 1; i < n; i ++ )
            if (l[i - 1] >= 0 && r[i + 2] >= 0)
            {
                VI t1, t2;
                t1.EB(l[i - 1]);
                t1.EB(a[i + 1]);
                t1.EB(a[i]);
                t1.EB(r[i + 2]);
                t2.EB(l[i - 1]);
                t2.EB(a[i]);
                t2.EB(a[i + 1]);
                t2.EB(r[i + 2]);
                if (check(t1) || check(t2))
                {
                    flag = true;
                    break;
                }
            }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}

// GOOD LUCK!!!
