
// Problem : D. Non-zero Segments
// Contest : Codeforces - Codeforces Round #674 (Div. 3)
// URL : https://codeforces.com/contest/1426/problem/D
// Memory Limit : 256 MB
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

const int N = 2000010, M = 1010;

int n, a[N];
LL s[N];
vector<PII> seq;

bool cmp(PII a, PII b)
{
	if (a.S != b.S) return a.S < b.S;
	else return a.F > b.F;
}

int main()
{
	IOS
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];

	map<LL, int> h;
	h[0LL] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		s[i] = s[i - 1] + a[i];
		if (h.count(s[i]))
		{
			int r = i - 1, l = h[s[i]] + 1;
			seq.EB(MP(l, r));
		}
		h[s[i]] = i;
	}
	
	sort(ALL(seq), cmp);
	int res = 0, pos = -0x3f3f3f3f;
	for (auto u : seq)
		if (u.F > pos)
		{
			res ++ ;
			pos = u.S;
		}
	cout << res << '\n';
    return 0;
}
