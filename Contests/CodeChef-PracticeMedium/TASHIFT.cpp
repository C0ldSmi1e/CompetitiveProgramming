
// Problem : Shift The String
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TASHIFT
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
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 2000010, M = 1010;

int n, m;
int ne[N];
char s[N], p[N];

int main()
{
	IOS
	
	cin >> n >> p + 1 >> s + 1;
	for (int i = 1; i <= n; i ++ ) s[i + n] = s[i];
	m = n, n *= 2;
	
	for (int i = 2, j = 0; i <= m; i ++ )
	{
	    while (j && p[i] != p[j + 1]) j = ne[j];
	    if (p[i] == p[j + 1]) j ++ ;
	    ne[i] = j;
	}
	
	int maxa = 0, res = 0;
	for (int i = 1, j = 0; i <= n; i ++ )
	{
	    while (j && s[i] != p[j + 1]) j = ne[j];
	    if (s[i] == p[j + 1]) j ++ ;
	    if (j > maxa)
	    {
	    	maxa = j;
	        res = i - maxa;
	    }
	}
	cout << res << '\n';
    return 0;
}
