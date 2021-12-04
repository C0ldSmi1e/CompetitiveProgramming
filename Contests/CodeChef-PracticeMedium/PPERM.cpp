
// Problem : Chef and Gift
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/CHGIFT1
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

const int N = 5000010, M = 1010, mod = 1e9 + 7;

int T;
int n;
int f[N];
int prime_cnt[N];
int primes[N], cnt;
bool st[N];

void init(int n)
{
	st[1] = true;
	for (int i = 2; i <= n; i ++ )
	{
		if (!st[i]) primes[cnt ++ ] = i;
		for (int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main()
{
	IOS
	
	init(N - 1);
	
	for (int i = 2; i < N; i ++ )
	{
		prime_cnt[i] = prime_cnt[i - 1];
		if (!st[i]) prime_cnt[i] ++ ;
	}
	
	f[1] = 1;
	for (int i = 2; i < N; i ++ ) f[i] = (LL)f[i - 1] * (prime_cnt[i] + 1) % mod;
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		cout << f[n] << '\n';
	}
    return 0;
}
