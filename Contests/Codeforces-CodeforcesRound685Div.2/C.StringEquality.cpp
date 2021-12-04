/**
* Author: Name
* Created Time: 2020-11-22 15:33:36
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int T;
int n, k;
string a, b;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> k >> a >> b;
        VE<int> cnt_a(27, 0), cnt_b(27, 0);

        for (auto &c : a) cnt_a[c - 'a'] ++ ;
        for (auto &c : b) cnt_b[c - 'a'] ++ ;

        bool flag = true;

        for (int i = 0; i < 26; i ++ )
        {
            if (cnt_a[i] < cnt_b[i]) flag = false;
            cnt_a[i] -= cnt_b[i];
            if (cnt_a[i] % k) flag = false;
            cnt_a[i + 1] += cnt_a[i];
        }

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

// GOOD LUCK!!!
