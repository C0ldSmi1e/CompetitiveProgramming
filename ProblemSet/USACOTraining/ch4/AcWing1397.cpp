/**
 * Author: Daniel
 * Created Time: 2020-12-28 09:50:23
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
const int N = 26, M = 1010;

string s;
VE<string> words;
int cnt[N];
map<char, int> h;

int get(string s)
{
    int res = 0;
    for (auto &c : s) res += h[c];
    return res;
}

void init()
{
    h['q'] = 7, h['w'] = 6, h['e'] = 1, h['r'] = 2, h['t'] = 2, h['y'] = 5, h['u'] = 4, h['i'] = 1, h['o'] = 3, h['p'] = 5;
    h['a'] = 2, h['s'] = 1, h['d'] = 4, h['f'] = 6, h['g'] = 5, h['h'] = 5, h['j'] = 7, h['k'] = 6, h['l'] = 3;
    h['z'] = 7, h['x'] = 7, h['c'] = 4, h['v'] = 6, h['b'] = 5, h['n'] = 2, h['m'] = 5;
}

bool check(string a, string b)
{
    bool flag = true;
    for (auto &c : a)
        if ( -- cnt[c - 'a'] < 0)
            flag = false;
    for (auto &c : b)
        if ( -- cnt[c - 'a'] < 0)
            flag = false;
    for (auto &c : a) cnt[c - 'a'] ++ ;
    for (auto &c : b) cnt[c - 'a'] ++ ;
    return flag;
}

// read the question carefully!!!
int main()
{
    SOS;

    init();

    cin >> s;
    for (auto &c : s) cnt[c - 'a'] ++ ;

    string t;
    while (cin >> t, t != ".")
    {
        bool flag = true;
        for (auto &c : t)
            if ( -- cnt[c - 'a'] < 0)
                flag = false;
        if (flag) words.EB(t);
        for (auto &c : t) cnt[c - 'a'] ++ ;
    }

    int res = 0;
    for (int i = 0; i < SZ(words); i ++ )
    {
        int tot = get(words[i]);
        res = max(res, tot);
        for (int j = i + 1; j < SZ(words); j ++ )
            if (check(words[i], words[j]))
                res = max(res, tot + get(words[j]));
    }

    cout << res << '\n';
    for (int i = 0; i < SZ(words); i ++ )
    {
        int tot = get(words[i]);
        if (tot == res)
        {
            cout << words[i] << '\n';
            continue;
        }
        for (int j = i + 1; j < SZ(words); j ++ )
            if (check(words[i], words[j]))
            {
                if (tot + get(words[j]) == res)
                    cout << words[i] << ' ' << words[j] << '\n';
            }
    }
    return 0;
}

// GOOD LUCK!!!
