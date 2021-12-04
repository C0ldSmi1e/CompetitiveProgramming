/**
*  Author: Daniel
*  Created Time: 2020-10-19 23:14:34
**/

// time-limit: 1000
#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define SZ(x) (int)x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 100010, M = 1010;

char s[N];

// read the question carefully!!!
int main()
{
    cin >> s + 1;
    int n = strlen(s + 1);

    cout << 4 << '\n';
    cout << "R " << n - 1 << '\n';
    cout << "R " << n << '\n';
    cout << "L " << n + 2 - 1 << '\n';
    cout << "L " << 2 << '\n';

    return 0;
}
