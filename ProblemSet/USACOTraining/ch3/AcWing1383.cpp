/**
 * Author: Daniel
 * Created Time: 2020-12-26 16:29:52
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 360, M = 1010;

int v[5];
int st[5][N];

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < 5; i ++ )
    {
        int cnt = 0;
        cin >> v[i] >> cnt;
        while (cnt -- )
        {
            int s, k;
            cin >> s >> k;
            for (int j = s; j <= s + k; j ++ ) st[i][j % N] = true;
        }
    }

    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
        {
            bool flag = true;
            for (int k = 0; k < 5; k ++ )
                if (!st[k][((j - i * v[k]) % N + N) % N])
                    flag = false;

            if (flag)
            {
                cout << i << '\n';
                return 0;
            }
        }

    cout << "none\n";
    return 0;
}

// GOOD LUCK!!!
