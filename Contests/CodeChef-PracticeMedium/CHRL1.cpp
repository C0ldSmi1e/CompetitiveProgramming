
// Problem : Lowest Common Ancestor
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TALCA
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

const int N = 100010, M = 1010;

int T;
int n, m;
int w[N], v[N];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i ++ ) cin >> w[i] >> v[i];
		
		int t = 0;
		map<int, int> f[2];
		f[t][0] = 0;
		
		for (int i = 1; i <= n; i ++ )
		{
			t ^= 1;
			for (auto u : f[t ^ 1])
			{
				f[t][u.F] = max(f[t][u.F], u.S);
				if (w[i] + u.F <= m)
					f[t][w[i] + u.F] = max(f[t][w[i] + u.F], u.S + v[i]);
			}
		}
		
		int res = 0;
		for (auto u : f[t]) res = max(res, u.S);
		cout << res << '\n';
	}
    return 0;
}
