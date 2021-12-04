
// Problem : Delivery Man
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TADELIVE
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

const int N = 100010, M = 1010;

int n, cnta, cntb;
struct Order
{
	int a, b, d;
	bool operator<(const Order &t) const
	{
		return d > t.d;
	}
}order[N];

int main()
{
	IOS
	
	cin >> n >> cnta >> cntb;
	for (int i = 0; i < n; i ++ ) cin >> order[i].a;
	for (int i = 0; i < n; i ++ )
	{
		cin >> order[i].b;
		order[i].d = abs(order[i].a - order[i].b);
	}
	sort(order, order + n);
	
	int res = 0;
	for (int i = 0; i < n; i ++ )
	{
		auto &e = order[i];
		if (e.a > e.b)
		{
			if (cnta)
			{
				res += e.a;
				cnta -- ;
			}
			else
			{
				res += e.b;
				cntb -- ;
			}
		}
		else
		{
			if (cntb)
			{
				res += e.b;
				cntb -- ;
			}
			else
			{
				res += e.a;
				cnta -- ;
			}
		}
	}
	cout << res << '\n';
    return 0;
}
