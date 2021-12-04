/**
 * Author: Daniel
 * Created Time: 2021-07-20 20:36:24
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1530/problem/E
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;



// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    while (T -- )
    {
        string s;
        cin >> s;
        int n = SZ(s);
        VI cnt(26);
        int tot = 0;
        for (auto &c : s)
        {
            cnt[c - 'a'] ++ ;
            tot += (int) (cnt[c - 'a'] == 1);
        }
        string res;
        auto add = [&](int c) -> void
        {
            assert(cnt[c] > 0);
            res += (char) ('a' + c);
            cnt[c] -- ;
        };
        auto solve = [&]() -> void
        {
            if (tot == 1) return;
            for (int i = 0; i < 26; i ++ )
                if (cnt[i] == 1)
                {
                    add(i);
                    return;
                }
            for (int i = 0; i < 26; i ++ )
                if (cnt[i] > 0)
                {
                    assert(cnt[i] > 1);
                    if (cnt[i] - 2 <= n - cnt[i])
                    {
                        add(i);
                        add(i);
                        int j = i + 1;
                        while (cnt[i] > 0)
                        {
                            while (cnt[j] == 0) j ++ ;
                            add(j);
                            add(i);
                            assert(j < 26);
                        }
                        return;
                    }
                    else break;
                }
            if (tot == 2)
            {
                for (int i = 0; i < 26; i ++ )
                    if (cnt[i] > 0)
                    {
                        add(i);
                        int j = i + 1;
                        while (cnt[j] == 0) j ++ ;
                        assert(j < 26);
                        while (cnt[j] > 0) add(j);
                        return;
                    }
            }
            else
            {
                for (int i = 0; i < 26; i ++ )
                    if (cnt[i] > 0)
                    {
                        add(i);
                        int j = i + 1;
                        while (cnt[j] == 0) j ++ ;
                        assert(j < 26);
                        add(j);
                        while (cnt[i] > 0) add(i);
                        int k = j + 1;
                        while (cnt[k] == 0) k ++ ;
                        add(k);
                        return;
                    }
            }
        };
        solve();
        for (int i = 0; i < 26; i ++ )
            while (cnt[i])
                add(i);
        assert(SZ(res) == n);
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
