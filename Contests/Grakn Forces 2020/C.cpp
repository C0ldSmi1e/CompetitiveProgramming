
// Problem: C. Discrete Acceleration
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

// check the limitation!!!
const int N = 100010, M = 1010;
const double eps = 1e-8;

int T;
int n, m;
double f[N], g[N];

bool check(double t)
{
	double sa = 0, sb = 0;
	double left_time = t;
	double cur_v = 1;
	
	for (int i = 1; i <= n; i ++ )
		if (left_time * cur_v >= (f[i] - sa))
		{
			left_time -= (f[i] - sa) / cur_v;
			cur_v += 1;
			sa = f[i];
		}
		else
		{
			sa += left_time * cur_v;
			left_time = 0;
			break;
		}
	if (left_time > 0) sa += left_time * cur_v;
	
	cur_v = 1;
	left_time = t;
	for (int i = 1; i <= n; i ++ )
		if (left_time * cur_v >= (g[i] - sb))
		{
			left_time -= (g[i] - sb) / cur_v;
			cur_v += 1;
			sb = g[i];
		}
		else
		{
			sb += left_time * cur_v;
			left_time = 0;
			break;
		}
	if (left_time > 0) sb += left_time * cur_v;

	return sa + sb >= (double)m;
}

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> f[i];
			g[n - i + 1] = m - f[i];
		}
		
		double l = 1, r = m / 2.0;
		for (int t = 0; t < 100; t ++ )
		{
			double mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid;
		}
		cout << 0.5 * (l + r) << '\n';
	}
    return 0;
}