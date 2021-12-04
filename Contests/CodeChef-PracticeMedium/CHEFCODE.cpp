
// Problem: Chef and Subsequences
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/CHEFCODE
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
const int N = 100010, M = 1010;

int n;
LL k;
vector<LL> a, b, f, g;

void input(int n, vector<LL> &a)
{
	while (n -- )
	{
		LL x;
		cin >> x;
		a.EB(x);
	}
}

void get(int n, vector<LL> &a, vector<LL> &f)
{
	for (int bit = 0; bit < 1 << n; bit ++ )
	{
		LL t = 1;
		bool flag = true;
		for (int i = 0; i < n; i ++ )
			if ((bit >> i) & 1)
			{
				if (t > k / a[i])
				{
					flag = false;
					break;
				}
				t *= a[i];
			}
		if (flag) f.EB(t);
	}
}

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> n >> k;
	input(n / 2, a);
	input(n - n / 2, b);
	
	get(n / 2, a, f);
	get(n - n / 2, b, g);
	
	sort(ALL(f));
	sort(ALL(g));
	
	LL res = 0;
	for (auto u : f)
		res += upper_bound(ALL(g), k / u) - g.begin();
		
	cout << res - 1 << '\n';
    return 0;
}
