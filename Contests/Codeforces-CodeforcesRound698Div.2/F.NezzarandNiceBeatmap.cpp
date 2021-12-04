/**
 * Author: Daniel
 * Created Time: 2021-02-20 01:04:03
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

struct Point
{
    double x, y;
    inline Point operator - (const Point& t) {return (Point) {x - t.x, y - t.y};}
    inline double operator & (const Point& t) {return x * t.x + y * t.y;}
};

const double eps = 1e-10;
inline int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

inline int dcmp(double a, double b)
{
    if (fabs(a - b) < eps) return 0;
    if (a < b) return -1;
    return 1;
}

inline double angle(Point a, Point b, Point c)
{
    c = c - b, a = a - b;
    return a & c;
}

Point p[N];
int order[N];

// read the question carefully!!!
int main()
{
    SOS;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> p[i].x >> p[i].y;
    order[1] = 1, order[2] = 2;
    for (int i = 3; i <= n; i ++ )
    {
        order[i] = i;
        for (int j = i; j >= 3; j -- )
            if (sgn(angle(p[order[j - 2]], p[order[j - 1]], p[order[j]])) <= 0)
                swap(order[j], order[j - 1]);
    }
    for (int i = 1; i <= n; i ++ )
    {
        cout << order[i];
        cout << " \n"[i == n];
    }
    return 0;
}

// GOOD LUCK!!!
