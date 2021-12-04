
// Problem: Tywins Tactics
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/TYTACTIC
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
const int N = 100010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int num[N];
int st[N], ed[N];
LL a[N];
LL tr[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int lowbit(int x)
{
	return x & -x;
}

// add c at index-x
// check data type!!!
void modify(int x, int c)
{
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

// get sum of [1,x]
// check data type!!!
LL sum(int x)
{
	
	LL res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

int dfs(int u, int fa, int time)
{
	st[u] = num[u] = time;
	
	int t = time;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (fa == j) continue;
		t = dfs(j, u, t + 1);
	}
	ed[u] = t;
	return t;
}

// read the question carefully!!!
int main()
{
	IOS
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs(1, -1, 1);

	for (int i = 1; i <= n; i ++ ) modify(num[i], a[i]);
	
	while (m -- )
	{
		string op;
		cin >> op;
		
		if (op[0] == 'Q')
		{
			int x;
			cin >> x;
			cout << sum(ed[x]) - sum(st[x] - 1) << '\n';
		}
		else
		{
			int x, c;
			cin >> x >> c;
			
			LL t = sum(num[x]) - sum(num[x] - 1);
			modify(num[x], -t);
			modify(num[x], c);
		}
	}
    return 0;
}
