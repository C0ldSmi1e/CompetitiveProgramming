
// Problem : D. Rescue Nibel!
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/D
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

const int N = 300010, M = 1010, mod = 998244353;

int n, k;
int l[N], r[N], order[N];
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

bool cmp(int i, int j)
{
	return l[i] < l[j];
}

int main()
{
	IOS
	
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i ++ )
	{
	    fact[i] = (LL)fact[i - 1] * i % mod;
	    infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
	}
	
	cin >> n >> k;
	iota(order + 1, order + 1 + n, 1);
	
	for (int i = 1; i <= n; i ++ ) cin >> l[i] >> r[i];
	
	sort(order + 1, order + n + 1, cmp);
	
	MSET S;
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int L = l[order[i]], R = r[order[i]];
		while (S.size() && *S.begin() < L) S.erase(S.begin());
		res = (res + C((int)S.size(), k - 1)) % mod;
		S.IS(R);
	}
	cout << res << '\n';
    return 0;
}
