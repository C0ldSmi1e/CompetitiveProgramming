
// Problem : Array Transform
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/ARRAYTRM
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

const int N = 1010, M = 1010;

int T;
int n, k;
int a[N], p[N], SIZE[N];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> k;
		for (int i = 0; i <= n; i ++ ) p[i] = i, SIZE[i] = 1;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		
		for (int i = 1; i <= n; i ++ )
			for (int j = i + 1; j <= n; j ++ )
				if (a[i] == a[j] || abs(a[i] - a[j]) % (1 + k) == 0)
				{
					int pa = find(i), pb = find(j);
					if (pa != pb)
					{
						SIZE[pb] += SIZE[pa];
						p[pa] = pb;
					}
				}
		
		bool flag = false;
		for (int i = 1; i <= n; i ++ )
			if (SIZE[find(i)] >= n - 1)
				flag = true;
		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
    return 0;
}
