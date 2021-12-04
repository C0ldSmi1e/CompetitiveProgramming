/**
 * Author: Daniel
 * Created Time: 2021-01-26 10:41:50
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
const int N = 100010, M = 1010;

int T;
int n;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        VE<string> a(n), b(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        for (int i = 0; i < n; i ++ ) cin >> b[i];

        for (int i = 0; i < n; i ++ )
        {
            if (a[i][0] == '1')
                for (int j = 0; j < n; j ++ )
                    a[i][j] ^= 1;
            if (b[i][0] == '1')
                for (int j = 0; j < n; j ++ )
                    b[i][j] ^= 1;
        }

        for (int j = 0; j < n; j ++ )
        {
            if (a[0][j] == '1')
                for (int i = 0; i < n; i ++ )
                    a[i][j] ^= 1;
            if (b[0][j] == '1')
                for (int i = 0; i < n; i ++ )
                    b[i][j] ^= 1;
        }
        cout << (a == b ? "YES\n" : "NO\n");
    }
    return 0;
}

// GOOD LUCK!!!
