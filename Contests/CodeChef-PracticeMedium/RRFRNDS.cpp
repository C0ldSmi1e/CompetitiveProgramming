
// Problem : Friends
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/RRFRNDS
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
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 2010, M = N * N;

int n;
int h[N], e[M], ne[M], idx;
char g[N][N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int main()
{
	IOS
	
	memset(h, -1, sizeof h);
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
	
	for (int i = 1; i <= n; i ++ )
		for (int j = i + 1; j <= n; j ++ )
			if (g[i][j] == '1')
			{
				add(i, j);
				add(j, i);
			}
	
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = i + 1; j <= n; j ++ )
			if (g[i][j] == '0')
				for (int v = h[j]; ~v; v = ne[v])
				{
					int u = e[v];
					if (g[u][i] == '1')
					{
						res += 2;
						break;
					}
				}
	cout << res << '\n';
    return 0;
}
