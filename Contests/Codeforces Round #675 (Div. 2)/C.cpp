
// Problem: C. Bargain
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/C
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
const int N = 100010, M = 1010, mod = 1e9 + 7;

int n;
int a[N];
char s[N];

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> s + 1;
	n = strlen(s + 1);
	
	for (int i = 1; i <= n; i ++ ) a[i] = s[i] - '0';
	
	int res = 0;
	int p = 1;
	for (int i = n; i >= 2; i -- )
	{
		res = (res + (LL)i * (i - 1) / 2LL % mod * a[i] % mod * p % mod) % mod;
		p = 10LL * p % mod;
	}

	p = 1;
	int sum = 0;
	for (int i = n - 1; i >= 1; i -- )
	{
		sum = (sum + (LL)p * (n - i) % mod) % mod;
		res = (res + (LL)a[i] * sum % mod) % mod;
		p = 10LL * p % mod;
	}
	
	cout << res << '\n';
    return 0;
}
