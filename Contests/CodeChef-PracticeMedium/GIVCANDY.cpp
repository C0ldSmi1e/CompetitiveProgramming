
// Problem : Sharing Candies
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/GIVCANDY
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

const int N = 100010, M = 1010;

int T;
LL a, b, c, d;

LL gcd(LL a, LL b)
{
	return b ? gcd(b, a % b) : a;
}

LL MOD(LL a, LL mod)
{
	return (a % mod + mod) % mod;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> a >> b >> c >> d;
		
		LL t = gcd(c, d);
		cout << min(MOD(a - b, t), MOD(b - a, t)) << '\n';
	}
    return 0;
}
