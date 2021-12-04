/**
 * Author: Daniel
 * Created Time: 2021-02-25 11:09:25
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
const int N = 200010, M = 1010;

int a, b, k;
int A[N], B[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> a >> b >> k;
    if (a == 0)
    {
        if (k) cout << "No\n";
        else
        {
            cout << "Yes\n";
            for (int i = 1; i <= a + b; i ++ ) cout << "1";
            cout << '\n';
            for (int i = 1; i <= a + b; i ++ ) cout << "1";
            cout << '\n';
        }
    }
    else if (b == 1)
    {
        if (k) cout << "No\n";
        else
        {
            cout << "Yes\n";
            cout << "1";
            for (int i = 1; i < a + b; i ++ ) cout << "0";
            cout << '\n';
            cout << "1";
            for (int i = 1; i < a + b; i ++ ) cout << "0";
            cout << '\n';
        }
    }
    else
    {
        if (k <= a + b - 2)
        {
            cout << "Yes\n";
            for (int i = 1; i <= b; i ++ ) A[i] = B[i] = 1;
            if (k <= a)
            {
                B[b] = 0;
                B[b + k] = 1;
            }
            else
            {
                B[b] = 0;
                B[a + b] = 1;
                k -= a;
                for (int i = b - 1; k; k -- , i -- ) 
                {
                    B[i] = 0;
                    B[i + 1] = 1;
                }
            }
            for (int i = 1; i <= a + b; i ++ ) cout << A[i];
            cout << '\n';
            for (int i = 1; i <= a + b; i ++ ) cout << B[i];
            cout << '\n';
        }
        else cout << "No\n";
    }
    return 0;
}

// GOOD LUCK!!!
