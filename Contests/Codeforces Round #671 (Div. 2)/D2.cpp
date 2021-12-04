
// Problem : D2. Sage's Birthday (hard version)
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/D2
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

int n, a[N];

bool check(int x)
{
	if (n - x - 1 < x) return false;
	int cnt = 0;
	for (int i = 1, j = x + 1; i <= x; i ++ )
	{
		while (j < n && (a[i] >= a[j] || a[i] >= a[j + 1])) j ++ ;
		if (j < n) cnt ++ ;
		j ++ ;
	}
	return cnt >= x;
}

int main()
{
	IOS
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << r << '\n';
	
	for (int i = 0, j = r + 1; i < n - r - (r + 1); i ++ , j ++ )
		cout << a[j] << ' ';
	
	for (int i = 0, j = 1, k = n - r; i < r + r + 1; i ++ )
		if (i & 1) cout << a[j ++ ] << ' ';
		else cout << a[k ++ ] << ' ';
	cout << '\n';
    return 0;
}
