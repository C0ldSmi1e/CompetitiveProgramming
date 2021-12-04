
// Problem: D. Searchlights
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int N = 1000010, M = 1010;

int n, m;
int a[N], b[N], c[N], d[N];
int len[N];

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i] >> b[i];
	for (int i = 1; i <= m; i ++ ) cin >> c[i] >> d[i];
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			if (c[j] >= a[i])
				len[c[j] - a[i]] = max(len[c[j] - a[i]], d[j] - b[i] + 1);
	
	int res = 0x3f3f3f3f;
	int maxa = 0;
	for (int i = N - 1; i >= 0; i -- )
	{
		maxa = max(maxa, len[i]);
		res = min(res, i + maxa);
	}
	cout << res << '\n';
    return 0;
}