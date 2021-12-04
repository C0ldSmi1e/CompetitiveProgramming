
// Problem : Saving a gift of love
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/ASHIGIFT
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int N = 10010, M = 1010;

int T;
int d, n, m;
int x[N], p[N];
LL y[N], q[N], r[N];

bool check(LL st)
{
	LL tot = st;
	for (int i = 1, j = 1; i <= n; i ++ )
	{
		while (j <= m && p[j] <= x[i])
		{
			if (tot >= q[j]) tot += r[j];
			j ++ ;
		}
		if (tot <= y[i]) return false;
		else tot -= y[i];
	}
	return true;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> d >> n;
		
		LL L = 0, R = 1;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> x[i] >> y[i];
			R += y[i];
		}
		
		cin >> m;
		for (int i = 1; i <= m; i ++ ) cin >> p[i] >> q[i] >> r[i];
		
		while (L < R)
		{
			LL mid = L + R >> 1LL;
			if (check(mid)) R = mid;
			else L = mid + 1LL;
		}
		cout << R << '\n';
	}
    return 0;
}
