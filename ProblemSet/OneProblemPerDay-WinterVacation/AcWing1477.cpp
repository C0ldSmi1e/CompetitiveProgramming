/**
 * Author: Daniel
 * Created Time: 2021-02-15 13:49:57
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

string s;
map<char, string> mp;

// read the question carefully!!!
int main()
{
    SOS;

    mp['0'] = "zero";
    mp['1'] = "one";
    mp['2'] = "two";
    mp['3'] = "three";
    mp['4'] = "four";
    mp['5'] = "five";
    mp['6'] = "six";
    mp['7'] = "seven";
    mp['8'] = "eight";
    mp['9'] = "nine";

    cin >> s;
    int tot = 0;
    for (auto &c : s) tot += c - '0';
    string t;
    if (tot)
        while (tot)
        {
            t += tot % 10 + '0';
            tot /= 10;
        }
    else t = "0";
    reverse(ALL(t));
    for (auto &c : t) cout << mp[c] << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
