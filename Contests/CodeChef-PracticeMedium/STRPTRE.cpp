
// Problem : Strip in a Tree!
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/STRPTRE
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int N = 100010, M = 1010, mod = 1e9 + 7;

int T;
int n, f[N];

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int sub(int a, int b)
{
	return ((a - b) % mod + mod) % mod;
}

int main()
{
	IOS
	
	for (int i = 1; i < N; i ++ ) f[i] = qp(2, i)  * ((i + 1LL) / 2LL) % mod * 2LL % mod;
	for (int i = 1; i < N; i ++ ) f[i] = (f[i] + f[i - 1]) % mod;
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		int A = f[n] % mod;
		int B = 2LL * sub(qp(2, n + 1), 1) % mod * sub(qp(2, n + 1), 2) % mod;
		int res = (LL)A * qp(B, mod - 2) % mod;
		cout << res << '\n';
	}
    return 0;
}
