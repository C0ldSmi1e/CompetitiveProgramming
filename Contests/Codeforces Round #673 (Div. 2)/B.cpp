
// Problem : B. Two Arrays
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int N = 100010, M = 1010;

int T;
int n, m;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		
		vector<int> a(n), res(n);
		for (auto &u : a) cin >> u;
		
		for (int i = 0, j = 0; i < SZ(a); i ++ )
			if (a[i] * 2 < m) res[i] = 1;
			else if (a[i] * 2 > m) res[i] = 0;
			else
			{
				res[i] = j;
				j ^= 1;
			}
		
		for (auto u : res) cout << u << ' ';
		cout << '\n';
	}
    return 0;
}
