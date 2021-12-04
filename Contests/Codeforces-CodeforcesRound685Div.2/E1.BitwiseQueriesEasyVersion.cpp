/**
* Author: Name
* Created Time: 2020-11-22 16:34:02
**/

// time-limit: 4000
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

int n;
int XOR[N];

int ask(string s, int i, int j)
{
    cout << s << ' ' << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int x)
{
    cout << " " << x;
    cout.flush();
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;

    for (int i = 2; i <= n; i ++ ) XOR[i] = ask("XOR", 1, i);

    int and12 = ask("AND", 1, 2);
    int and13 = ask("AND", 1, 3);
    int and23 = ask("AND", 2, 3);
    
    int a1 = (XOR[2] + XOR[3] + 2 * and12 + 2 * and13 - (XOR[2] ^ XOR[3]) - 2 * and23) / 2;
    cout << "!";
    cout.flush();
    answer(a1);
    for (int i = 2; i <= n; i ++ ) answer(a1 ^ XOR[i]);
    return 0;
}

// GOOD LUCK!!!
