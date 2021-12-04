
// Problem: Ancient Berland Roads
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/ABROADS
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
typedef priority_queue<LL> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 500010, M = 1010;

int n, m, q;
int p[N];
int x[N], y[N];
int popul[N];
int backup[N];
LL SIZE[N];
LL res[N];
PII e[N];
char type[N];
bool del[N];
multiset<LL> S;

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b)
{
	int pa = find(a), pb = find(b);
	if (pa != pb)
	{
		S.erase(S.find(SIZE[pa]));
		S.erase(S.find(SIZE[pb]));
		SIZE[pb] += SIZE[pa];
		S.IS(SIZE[pb]);
		p[pa] = pb;
	}
}

LL get()
{
	auto it = S.end();
	it -- ;
	return (*it);
}

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++ ) cin >> popul[i];
	for (int i = 1; i <= m; i ++ ) cin >> e[i].F >> e[i].S;
	for (int i = 1; i <= q; i ++ )
	{
		cin >> type[i];
		if (type[i] == 'D')
		{
			cin >> x[i];
			del[x[i]] = true;
		}
		else
		{
			cin >> x[i] >> y[i];
			backup[i] = popul[x[i]];
			popul[x[i]] = y[i];
		}
	}
	
	for (int i = 1; i <= n; i ++ )
	{
		p[i] = i;
		SIZE[i] = popul[i];
		S.IS(SIZE[i]);
	}
	
	for (int i = 1; i <= m; i ++ )
		if (!del[i])
			merge(e[i].F, e[i].S);
			
	res[q] = get();
	for (int i = q; i >= 1; i -- )
	{
		if (type[i] == 'D') merge(e[x[i]].F, e[x[i]].S);
		else
		{
			int pa = find(x[i]);
			S.erase(S.find(SIZE[pa]));
			SIZE[pa] -= popul[x[i]];
			popul[x[i]] = backup[i];
			SIZE[pa] += popul[x[i]];
			S.IS(SIZE[pa]);
		}
		res[i - 1] = get();
	}
	
	for (int i = 1; i <= q; i ++ ) cout << res[i] << '\n';
    return 0;
}
