
// Problem : E. Decryption
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int N = 100010, M = 1010;

int T;
int n;

bool is_prime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i ++ )
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		vector<int> factor;
		for (int i = 2; i <= n / i; i ++ )
			if (n % i == 0)
			{
				factor.PB(i);
				factor.PB(n / i);
			}
	
		factor.PB(n);
		sort(ALL(factor));
		factor.erase(unique(ALL(factor)), factor.end());
		
		if (SZ(factor) == 3 && is_prime(factor[0]) && is_prime(factor[1]))
		{
			for (auto u : factor) cout << u << ' ';
			cout << "\n1\n";
			continue;
		}
		
		vector<int> primes;
		for (auto u : factor)
			if (is_prime(u))
				primes.PB(u);
		
		vector<int> res;
		set<int> S;
		S.IS(n);
		
		for (int i = 0; i < SZ(primes) - 1; i ++ )
		{
			S.IS(primes[i]);
			S.IS(primes[i] * primes[i + 1]);
			res.PB(primes[i]);
			for (auto u : factor)
				if (!S.count(u) && u % primes[i] == 0)
				{
					res.PB(u);
					S.IS(u);
				}
			res.PB(primes[i] * primes[i + 1]);
		}	
		
		for (auto u : factor)
			if (u % primes[SZ(primes) - 1] == 0 && !S.count(u))
			{
				res.PB(u);
				S.IS(u);
			}
		res.PB(n);
		
		for (auto u : res) cout << u << ' ';
		cout << "\n0\n";
	}
    return 0;
}
