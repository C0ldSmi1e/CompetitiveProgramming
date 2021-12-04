
// Problem : C2. Pokémon Army (hard version)
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/C2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N = 300010, M = 1010;

int T;
int n, m;
int a[N];

int get(int i)
{
	if (i < 1 || i > n) return 0;
	else if (i == n) return a[i];
	else return max(0, a[i] - a[i + 1]);
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		
		LL res = 0;
		for (int i = 1; i <= n; i ++ ) res += get(i);
		cout << res << '\n';
		
		while (m -- )
		{
			int l, r;
			cin >> l >> r;
			res -= get(l - 1);
			res -= get(l);
			res -= get(r);
			if (l != r - 1) res -= get(r - 1);
			swap(a[l], a[r]);
			res += get(l - 1);
			res += get(l);
			res += get(r);
			if (l != r - 1) res += get(r - 1);
			cout << res << '\n';
		}
	}
    return 0;
}
