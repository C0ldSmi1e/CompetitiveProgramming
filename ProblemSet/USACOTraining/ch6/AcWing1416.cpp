/**
 * Author: Daniel
 * Created Time: 2021-01-31 16:50:32
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
typedef vector<LL> VL;
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
const int N = 4, M = 1010;

PII rec[N];
VE<PII> res;

void update(int h, int w)
{
    if (h > w) swap(h, w);
    if (!SZ(res) || res[0].F * res[0].S > h * w)
    {
        res.clear();
        res.EB(h, w);
    }
    else if (res[0].F * res[0].S == h * w) res.EB(h, w);
}

void work()
{
    auto ah = rec[0].F, aw = rec[0].S, bh = rec[1].F, bw = rec[1].S;
    auto ch = rec[2].F, cw = rec[2].S, dh = rec[3].F, dw = rec[3].S;

    update(max(ah, max(bh, max(ch, dh))), aw + bw + cw + dw);
    update(dh + max(ah, max(bh, ch)), max(aw + bw + cw, dw));
    update(max(ch + max(ah, bh), dh), dw + max(cw, aw + bw));
    update(max(ah, max(bh + ch, dh)), aw + max(bw, cw) + dw);
    update(max(ah + bh, max(ch, dh)), max(aw, bw) + cw + dw);
    if (bw >= aw && ch >= bh)
    {
        if (ch >= ah + bh) update(ch + dh, max(bw + cw, dw));
        else if (dw + aw <= bw + cw) update(max(ah + bh, ch + dh), bw + cw);
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < N; i ++ ) cin >> rec[i].F >> rec[i].S;

    sort(rec, rec + N);
    do
    {
        for (int mask = 0; mask < 1 << 16; mask ++ )
        {
            for (int i = 0; i < 4; i ++ )
                if ((mask >> i) & 1)
                    swap(rec[i].F, rec[i].S);

            work();

            for (int i = 0; i < 4; i ++ )
                if ((mask >> i) & 1)
                    swap(rec[i].F, rec[i].S);
        }
    } while (next_permutation(rec, rec + N));

    sort(ALL(res));
    res.erase(unique(ALL(res)), res.end());

    cout << res[0].F * res[0].S << '\n';
    for (auto [x, y] : res)
        cout << x << ' ' << y << '\n';
    return 0;
}

// GOOD LUCK!!!
