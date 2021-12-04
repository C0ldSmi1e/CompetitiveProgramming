/**
 * Author: Daniel
 * Created Time: 2020-12-09 17:47:14
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
#define SZ(x) ((int)x.size())
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

int n;
int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
int cnt[N];
string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0, x = i; j < 13; j ++ )
            while (x >= num[j])
            {
                x -= num[j];
                for (auto &c : s[j]) cnt[c - 'A'] ++ ;
            }

    string t = "IVXLCDM";
    for (int i = 0; i < SZ(t); i ++ )
        if (cnt[t[i] - 'A'])
            cout << t[i] << ' ' << cnt[t[i] - 'A'] << '\n';
    return 0;
}

// GOOD LUCK!!!
