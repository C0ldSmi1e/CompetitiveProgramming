/**
*  Author: Daniel
*  Created Time: 2020-10-30 08:51:49
**/

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define PII P(int, int)
#define lowbit(x) (x & -x)
#define P(x, y) pair<x, y>
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define HEAP(x) priority_queue<x>
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define RHEAP(x) priority_queue<x, vector<x>, greater<x> >
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<< p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}

typedef long long LL;

// check the limitation!!!
const int N = 100010, M = 1010;

int n;

// read the question carefully!!!
int main()
{
    IOS

    cin >> n;
    vector<P(char, int)> a(2 * n);

    int t = 0;
    bool flag = true;
    for (int i = 0; i < 2 * n; i ++ )
    {
        char c;
        int x = -1;
        cin >> c;

        if (c == '-')
        {
            cin >> x;
            if (n - x + 1 < t) flag = false;
            t -- ;
        }
        else t ++ ; 

        if (t < 0) flag = false;
        a[i] = MP(c, x);
    }

    RHEAP(int) heap;
    vector<int> res;
        
    for (int i = 2 * n - 1; i >= 0; i -- )
    {
        int x = a[i].S;
        char c = a[i].F;
        
        if (c == '-') 
        {
            if (SZ(heap) && x > heap.top()) flag = false;
            heap.push(x);
        }
        else
        {
            if (!SZ(heap)) flag = false;
            else
            {
                res.EB(heap.top());
                heap.pop();
            }
        }
    }

    if (flag)
    {
        cout << "YES\n";
        reverse(ALL(res));
        for (auto &u : res) cout << u << ' ';
        cout << '\n';
    }
    else cout << "NO\n";
    return 0;
}
