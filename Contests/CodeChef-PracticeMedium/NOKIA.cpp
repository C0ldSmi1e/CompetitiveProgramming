
// Problem : Connecting Soldiers
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/NOKIA
// Memory Limit : 256 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 35, M = 1010;

int T;
int n, m;
int f[N], g[N];

int main()
{
	IOS
	
	memset(g, 0x3f, sizeof g);
	f[0] = g[0] = 0;
	for (int i = 1; i < N; i ++ )
		for (int j = 1; j <= i; j ++ )
		{
			f[i] = max(f[i], i + 1 + f[j - 1] + f[i - j]);
			g[i] = min(g[i], i + 1 + g[j - 1] + g[i - j]);
		}
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		if (m < g[n]) cout << -1 << '\n';
		else if (m <= f[n]) cout << 0 << '\n';
		else cout << m - f[n] << '\n';
	}
    return 0;
}
