
// Problem : Lowest Common Ancestor
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TALCA
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

const int N = 200010, M = 1010;

int n, m;
int a[N];
LL f[N];

int main()
{
	IOS
	
	cin >> n;
	vector<int> one, two;
	for (int i = 0; i < n; i ++ )
	{
		int w, c;
		cin >> w >> c;
		if (w == 1) one.PB(c);
		else two.PB(c);
		m += w;
	}
	
	sort(ALL(one));
	sort(ALL(two));
	auto t1 = one, t2 = two;
	
	for (int i = 2; i <= m; i += 2)
	{
		int s1 = 0, s2 = 0;
		int one_cnt = 0;
		if (one.size() >= 2)
		{
			s1 += one.back();
			s1 += one[one.size() - 2];
			one_cnt = 2;
		}
		else if (one.size() >= 1)
		{
			s1 += one.back();
			one_cnt = 1;
		}
		
		if (two.size() >= 1) s2 = two.back();
		
		if (s1 > s2)
		{
			f[i] = f[i - 2] + s1;
			if (one_cnt == 1) one.pop_back();
			else
			{
				one.pop_back();
				one.pop_back();
			}
		}
		else
		{
			f[i] = f[i - 2] + s2;
			two.pop_back();
		}
	}
	
	one = t1, two = t2;
	if (one.size() >= 1)
	{
		f[1] = one.back();
		one.pop_back();
	}
	for (int i = 3; i <= m; i += 2)
	{
		int s1 = 0, s2 = 0;
		int one_cnt = 0;
		if (one.size() >= 2)
		{
			s1 += one.back();
			s1 += one[one.size() - 2];
			one_cnt = 2;
		}
		else if (one.size() >= 1)
		{
			s1 += one.back();
			one_cnt = 1;
		}
		
		if (two.size() >= 1) s2 = two.back();
		
		if (s1 > s2)
		{
			f[i] = f[i - 2] + s1;
			if (one_cnt == 1) one.pop_back();
			else
			{
				one.pop_back();
				one.pop_back();
			}
		}
		else
		{
			f[i] = f[i - 2] + s2;
			two.pop_back();
		}
	}
	
	for (int i = 1; i <= m; i ++ ) cout << f[i] << ' ';
	cout << '\n';
    return 0;
}
