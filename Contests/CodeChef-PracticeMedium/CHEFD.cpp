
// Problem : Chef and medium problem 2
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/CHEFD
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

const int N = 100010, M = 1010;

int n, m;
int a[N];
set<int> S[3];

void add(int x, int i)
{
	if (x % 2 == 0) S[0].IS(i);
	if (x % 3 == 0) S[1].IS(i);
	if (x % 5 == 0) S[2].IS(i);
}

void del(int x, int i)
{
	if (x % 2 == 0) S[0].erase(i);
	if (x % 3 == 0) S[1].erase(i);
	if (x % 5 == 0) S[2].erase(i);
}

int main()
{
	IOS
	
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		add(a[i], i);
	}
	
	cin >> m;
	while (m -- )
	{
		int type;
		cin >> type;
		
		if (type == 1)
		{
			int l, r, p;
			cin >> l >> r >> p;
			
			int i;
			if (p == 2) i = 0;
			else if (p == 3) i = 1;
			else i = 2;
			
			vector<int> del_idx;
			
			auto st = S[i].lower_bound(l);
			for (auto it = st; it != S[i].end() && *it <= r; it ++ )
			{
				a[*it] /= p;
				if (a[*it] % p) del_idx.EB(*it);
			}
			
			for (auto u : del_idx) S[i].erase(u);
		}
		else
		{
			int l, d;
			cin >> l >> d;
			del(a[l], l);
			a[l] = d;
			add(d, l);
		}
	}
	
	for (int i = 1; i <= n; i ++ ) cout << a[i] << ' ';
	cout << '\n';
    return 0;
}
