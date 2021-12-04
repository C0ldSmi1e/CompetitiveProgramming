
// Problem : E. XOR Inverse
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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

const int N = 5000010, M = 30;

int n;
LL f[M][2];
int son[N][2], idx;
vector<int> g[N];

void insert(int x, int pos)
{
	int p = 0;
    for (int i = M - 1; i >= 0; i -- )
    {
        int u = ((x >> i) & 1);
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        g[p].EB(pos);
    }
}

void get(int p, int depth)
{
	int l = son[p][0], r = son[p][1];
	
	if (l) get(l, depth - 1);
	if (r) get(r, depth - 1);
	if (!l || !r) return;
	
	LL res = 0;
	for (int i = 0, j = 0; i < SZ(g[l]); i ++ )
	{
		while (j < SZ(g[r]) && g[r][j] < g[l][i]) j ++ ;
		res += j;
	}

	f[depth][0] += res;
	f[depth][1] += SZ(g[l]) * (LL)SZ(g[r]) - res;
}

int main()
{
	IOS
	
	cin >> n;
	for (int i = 0; i < n; i ++ ) 
	{
		int x;
		cin >> x;
		insert(x, i);
	}

	get(0, 29);
	
	LL res = 0;
	int x = 0;
	for (int i = 0; i < M; i ++ )
		if (f[i][0] > f[i][1]) res += f[i][1], x |= (1 << i);
		else res += f[i][0];
		
	cout << res << ' ' << x << '\n';
    return 0;
}
