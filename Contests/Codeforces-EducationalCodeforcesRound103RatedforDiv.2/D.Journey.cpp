/**
 * Author: Daniel
 * Created Time: 2021-02-02 23:34:05
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
const int N = 300010, M = 1010;

int T;
int n;
int l1[N], l2[N];
int r1[N], r2[N];
char s[N], t[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> s + 1;
        l1[0] = l1[1] = l1[n + 1] = l1[n] = 0;
        l2[0] = l2[1] = l2[n + 1] = l2[n] = 0;
        r1[0] = r1[1] = r1[n + 1] = r1[n] = 0;
        r2[0] = r2[1] = r2[n + 1] = r2[n] = 0;

        for (int i = 1; i <= n; i ++ ) t[i] = s[i] == 'L' ? 'R' : 'L';

        for (int i = 1; i <= n; i ++ )
        {
            if (s[i] == 'L') l1[i] = 1 + l2[i - 1];
            else l1[i] = 0;
            if (t[i] == 'L') l2[i] = 1 + l1[i - 1];
            else l2[i] = 0;
        }

        for (int i = n - 1; i >= 0; i -- )
        {
            if (s[i + 1] == 'R') r1[i] = 1 + r2[i + 1];
            else r1[i] = 0;
            if (t[i + 1] == 'R') r2[i] = 1 + r1[i + 1];
            else r2[i] = 0;
        }

        for (int i = 0; i <= n; i ++ ) 
        {
            cout << l1[i] + 1 + r1[i];
            cout << " \n"[i == n];
        }
    }
    return 0;
}

// GOOD LUCK!!!
