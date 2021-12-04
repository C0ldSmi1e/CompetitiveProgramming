/**
*  Author: Daniel
*  Created Time: 2020-10-18 23:11:40
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
const int N = 100010, M = 1010;

int n;
int res[N];
int tr[N];
struct Cow
{
    int s, e, id;
    bool operator<(const Cow &t) const
    {
        if (e != t.e) return e > t.e;
        else return s < t.s;
    }
}cow[N];

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
    while (cin >> n && n)
    {
        memset(tr, 0, sizeof tr);

        for (int i = 1; i <= n; i ++ )                        
        {                                                         
            int s, e;                                             
            scanf("%d%d", &s, &e);
            cow[i].s = s + 1, cow[i].e = e + 1, cow[i].id = i;    
        }                                                         
                                                                  
        sort(cow + 1, cow + 1 + n);                               
                                                              
        for (int i = 1; i <= n; i ++ )                            
        {                                                     
            int s = cow[i].s, e = cow[i].e, id = cow[i].id;       
            if (e == cow[i - 1].e && s == cow[i - 1].s) res[id] = res[cow[i - 1].id];
            else res[id] = sum(s);
            add(s, 1);
        }                                                         
                                                                  
        for (int i = 1; i <= n; i ++ )                            
        {                                                     
            printf("%d", res[i]);
            if (i < n) printf(" ");
            else printf("\n");
        }                                                         
    }
    return 0;
}

