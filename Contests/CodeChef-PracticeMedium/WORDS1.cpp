
// Problem : Play on Words
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/WORDS1
// Memory Limit : 256 MB
// Time Limit : 6600 ms
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

const int N = 100010, M = 26;

int T;
int n, m;
int l[M], r[M];
int p[N];
char s[N];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d", &T);
	while (T -- )
	{
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		for (int i = 0; i < M; i ++ ) p[i] = i;
		
		scanf("%d", &n);
		for (int i = 0; i < n; i ++ )
		{
			scanf("%s", s);
			m = strlen(s);
			int a = s[0] - 'a', b = s[m - 1] - 'a';
			l[a] ++ , r[b] ++ ;
			int pa = find(a), pb = find(b);
			p[pb] = pa;
		}
		
		int cnt = 0, front = 0, back = 0;
		bool flag = true;
		for (int i = 0; i < M; i ++ )
		{
			if ((l[i] || r[i]) && p[i] == i) cnt ++ ;
			if (l[i] - r[i] == 1) front ++ ;
			if (r[i] - l[i] == 1) back ++ ;
			if (abs(l[i] - r[i]) > 1) flag = false;
		}
			
		if (cnt > 1 || front > 1 || back > 1) flag = false;
		
		if (flag) puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
    return 0;
}
