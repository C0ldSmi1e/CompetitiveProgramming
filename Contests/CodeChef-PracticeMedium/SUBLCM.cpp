
// Problem : Subarray LCM
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/SUBLCM
// Memory Limit : 256 MB
// Time Limit : 2500 ms
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

const int N = 1000010, M = 1010;

int T;
int n, a[N];
int f[N], p[N];
vector<int> primes[N];

void init(int n)
{
	for (int i = 2; i <= n; i ++ )
	{
		int x = i;
		for (int j = 2; j <= x / j; j ++ )
			if (x % j == 0)
			{
				primes[i].PB(j);
				while (x % j == 0) x /= j;
			}
		if (x > 1) primes[i].PB(x);
	}
}

int get(int x, int idx)
{
	auto t = primes[x];
	
	int max_idx = 0;
	for (auto u : t)
	{
		max_idx = max(max_idx, p[u]);
		p[u] = idx;
	}
	return max_idx;
}

int main()
{
	IOS
	
	init(N - 1);
	
	cin >> T;
	while (T -- )
	{
		memset(p, 0, sizeof p);
		memset(f, 0, sizeof f);
		
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		
		for (int i = 1; i <= n; i ++ )
			f[i] = min(f[i - 1] + 1, i - get(a[i], i));
		
		int res = -1;
		for (int i = 1; i <= n; i ++ )
			if (f[i] > 1)
				res = max(res, f[i]);
		cout << res << '\n';			
	}
    return 0;
}
