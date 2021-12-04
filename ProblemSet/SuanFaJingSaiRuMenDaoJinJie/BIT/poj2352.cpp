/**
*  Author: Daniel
*  Created Time: 2020-10-18 22:18:55
**/

#include <queue>    
#include <vector>   
#include <cstdio>   
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <iostream> 
#include <algorithm>

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
const int N = 320010, M = 1010;

int n;
int res[N];
int tr[N];

#define lowbit(x) x & -x

void add(int x, int c)
{
    for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

// read the question carefully!!!
int main()
{
    IOS

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        x ++ ;
        res[sum(x)] ++ ;
        add(x, 1);
    }

    for (int i = 0; i < n; i ++ ) cout << res[i] << '\n';
    return 0;
}

