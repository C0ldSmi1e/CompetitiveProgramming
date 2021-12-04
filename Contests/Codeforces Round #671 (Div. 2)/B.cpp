
// Problem : B. Stairs
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB push_back
#define SZ(x) x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 32, M = 1010;

int T;
LL n;

LL get(LL x)
{
	return (x + 1LL) * x / 2LL;
}

int main()
{
	IOS

	cin >> T;
	while (T -- )
	{
		cin >> n;
		int res = 0;
		for (int i = 1; get((1LL << i) - 1) <= n; i ++ )
		{
			res ++ ;
			n -= get((1LL << i) - 1);
		}
		cout << res << '\n';
	}
    return 0;
}
