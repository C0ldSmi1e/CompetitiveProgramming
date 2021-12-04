/**
 * Author: Daniel
 * Created Time: 2021-03-14 09:59:17
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef vector<pair<int, int> > VPII;

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

int n;
char s[N], x[N];
bool f[N][7];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> s + 1 >> x + 1;
    f[n][0] = true;
    for (int i = n; i; i -- )
    {
        int d = s[i] - '0';
        if (x[i] == 'T')
        {
            for (int j = 0; j < 7; j ++ )
                if (f[i][(j * 10 + d) % 7] || f[i][(j * 10) % 7])
                    f[i - 1][j] = true;
        }
        else
        {
            for (int j = 0; j < 7; j ++ )
                if (f[i][(j * 10 + d) % 7] && f[i][(j * 10) % 7])
                    f[i - 1][j] = true;
        }
    }
    cout << (f[0][0] ? "Takahashi\n" : "Aoki\n");
    return 0;
}

// GOOD LUCK!!!
