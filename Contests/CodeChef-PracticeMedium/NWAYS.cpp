
// Problem: Number of Ways 
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/NWAYS
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
const int N = 2000010, M = 1010, mod = 1e9 + 7;

int T;
int n, k;
int fact[N], infact[N];

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

// can use when the mod number is a prime number
// C(a, b) = fact[a] * infact[a - b] * infact[b]
int C(int a, int b)
{
	if (a < b) return 0;
	int res = (LL)fact[a] * infact[a - b] % mod * infact[b] % mod;
	return res;
}

// read the question carefully!!!
int main()
{
	IOS
	
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i ++ )
	{
	    fact[i] = (LL)fact[i - 1] * i % mod;
	    infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
	}
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> k;
		int res = C(n + k + 1, k + 2);
		res = 2LL * res % mod;
		res = ((res - n) % mod + mod) % mod;
		cout << res << '\n';
	}
    return 0;
}
