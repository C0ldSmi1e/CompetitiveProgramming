
// Problem : C. Increase and Copy
// Contest : Codeforces - Codeforces Round #674 (Div. 3)
// URL : https://codeforces.com/contest/1426/problem/C
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
LL n;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		
		LL l = 0, r = n;
		while (l < r)
		{
			LL mid = l + r + 1LL >> 1LL;
			if (mid * mid <= n) l = mid;
			else r = mid - 1LL;
		}
		LL a1 = 2 * (r - 1) + (n - r * r + r - 1) / r;
		
		l = 0, r = n;
		while (l < r)
		{
			LL mid = l + r >> 1LL;
			if (mid * mid >= n) r = mid;
			else l = mid + 1LL;
		}
		LL a2 = 2 * (r - 1) + n / (r * r);
		
		cout << min(a1, a2) << '\n';
	}
    return 0;
}
