
// Problem : ABC-Strings
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/ABCSTR
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N = 1000010, M = 1010;

int n;
int a[N], b[N], c[N];
char s[N];
map<PII, int> h;

int main()
{
	IOS
	
	cin >> s + 1;
	n = strlen(s + 1);
	
	for (int i = 1; i <= n; i ++ )
	{
		a[i] = a[i - 1];
		b[i] = b[i - 1];
		c[i] = c[i - 1];
		if (s[i] == 'A') a[i] ++ ;
		else if (s[i] == 'B') b[i] ++ ;
		else c[i] ++ ;
	}
	
	LL res = 0;
	h[MP(0, 0)] = 1;
	for (int i = 1; i <= n; i ++ )
	{
		int tab = a[i] - b[i];
		int tac = a[i] - c[i];
		auto p = MP(tab, tac);
		if (h.count(p)) res += h[p];
		h[p] ++ ;
	}
	cout << res << '\n';
    return 0;
}
