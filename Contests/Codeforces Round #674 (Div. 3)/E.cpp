
// Problem : E. Rock, Paper, Scissors
// Contest : Codeforces - Codeforces Round #674 (Div. 3)
// URL : https://codeforces.com/contest/1426/problem/E
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

const int N = 6, M = 1010;

int n;
vector<int> a, b;


int main()
{
	IOS
	
	cin >> n;
	
	a.resize(3), b.resize(3);
	for (auto &u : a) cin >> u;
	for (auto &u : b) cin >> u;
	
	int mina = 0x3f3f3f3f, maxa = 0;
	maxa = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	
	vector<PII> order;
	order.EB(MP(0, 0));
	order.EB(MP(0, 2));
	order.EB(MP(1, 1));
	order.EB(MP(1, 0));
	order.EB(MP(2, 2));
	order.EB(MP(2, 1));
	sort(ALL(order));
	
	do
	{
		vector<int> ta = a, tb = b;
		for (auto u : order)
		{
			int t = min(ta[u.F], tb[u.S]);
			ta[u.F] -= t, tb[u.S] -= t;
		}
		int cur = min(ta[0], tb[1]) + min(ta[1], tb[2]) + min(ta[2], tb[0]);
		mina = min(mina, cur);
	}while (next_permutation(ALL(order)));
	cout << mina << ' ' << maxa << '\n';
    return 0;
}
