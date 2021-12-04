/**
 * Author: Daniel
 * Created Time: 2021-02-05 22:36:03
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

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
int x, y;
string s;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> x >> y >> s;
        int L = 0, R = 0, U = 0, D = 0;
        for (auto &c : s)
            if (c == 'L') L ++ ;
            else if (c == 'R') R ++ ;
            else if (c == 'U') U ++ ;
            else if (c == 'D') D ++ ;

        bool flag = false;
        if (x > 0 && y > 0)
        {
            flag |= (R >= x && U >= y);
        }
        else if (x > 0 && y < 0)
        {
            flag |= (R >= x && D >= -y);
        }
        else if (x < 0 && y < 0)
        {
            flag |= (L >= -x && D >= -y);
        }
        else if (x < 0 && y > 0)
        {
            flag |= (L >= -x && U >= y);
        }
        else if (x == 0)
        {
            if (y > 0) flag |= (U >= y);
            else flag |= (D >= -y);
        }
        else if (y == 0)
        {
            if (x > 0) flag |= (R >= x);
            else flag |= (L >= -x);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}

// GOOD LUCK!!!
