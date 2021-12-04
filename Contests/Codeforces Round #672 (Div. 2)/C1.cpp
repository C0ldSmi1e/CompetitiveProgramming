
// Problem : C1. Pokémon Army (easy version)
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/C1
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define SZ(x) x.size()
#define EB emplace_back
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

const int N = 300010, M = 1010;

int T;
int n, m;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		
		vector<int> a(n);
		for (auto &u : a) cin >> u;
		
		vector<LL> mx(n + 1), mn(n + 1);
		for (int i = n - 1; i >= 0; i -- )
		{
			mx[i] = max(mx[i + 1], a[i] - mn[i + 1]);
			mn[i] = min(mn[i + 1], a[i] - mx[i + 1]);
		}
		cout << mx[0] << '\n';
	}
    return 0;
}
