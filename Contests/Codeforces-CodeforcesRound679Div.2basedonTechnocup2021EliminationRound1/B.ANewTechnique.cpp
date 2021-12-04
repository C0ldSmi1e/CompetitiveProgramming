/**
*  Author: Daniel
*  Created Time: 2020-10-29 21:59:28
**/

// time-limit: 1000
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

int T;
int n, m;

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;

        vector<vector<int>> row(n, vector<int>(m));
        vector<vector<int>> col(m, vector<int>(n));
        map<int, int> h;

        for (int i = 0; i < SZ(row); i ++ )
            for (int j = 0; j < SZ(row[i]); j ++ )
            {
                cin >> row[i][j];
                if (!j) h[row[i][j]] = i;
            }

        for (auto &a : col)
            for (auto &u : a)
                cin >> u;

        int idx;
        for (int i = 0; i < m; i ++ )
            if (h.count(col[i][0]))
            {
                idx = i;
                break;
            }

        for (auto &u : col[idx])
        {
            for (auto &v : row[h[u]])
                cout << v << ' ';
            cout << '\n';
        }
    }
    return 0;
}
