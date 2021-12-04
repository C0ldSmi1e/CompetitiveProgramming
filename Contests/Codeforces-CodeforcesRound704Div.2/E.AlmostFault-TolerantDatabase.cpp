/**
 * Author: Daniel
 * Created Time: 2021-02-25 13:44:31
**/

// time-limit: 2000
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

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

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) 
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) 
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }

void debug_out() { cout << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }

#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int n, m;
VE<VI> a;

bool check3(VI &t, int pos)
{
    t[pos] = -1;
    for (auto &u : a)
    {
        int cnt = 0;
        for (int i = 0; i < m; i ++ ) cnt += (t[i] != u[i]);
        if (cnt <= 2) continue;
        else if (cnt > 3) return false;
        else if (t[pos] != u[pos])
        {
            if (t[pos] == -1) t[pos] = u[pos];
            else return false;
        }
        else return false;
    }
    if (t[pos] == -1) t[pos] = 1;
    return true;
}

bool check4(VI &t)
{
    for (auto &u : a)
    {
        int cnt = 0;
        for (int i = 0; i < m; i ++ ) cnt += (u[i] != t[i]);
        if (cnt > 2) return false;
    }
    return true;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    a = VE<VI>(n, VI(m));
    for (auto &u : a)
        for (auto &v : u)
            cin >> v;

    int mx = 0;
    for (int i = 1; i < n; i ++ )
    {
        int cnt = 0;
        for (int j = 0; j < m; j ++ ) cnt += (a[0][j] != a[i][j]);
        mx = max(mx, cnt);
    }
    if (mx >= 5)
    {
        cout << "No\n";
        return 0;
    }
    if (mx <= 2)
    {
        cout << "Yes\n";
        for (auto &u : a[0]) cout << u << ' ';
        cout << '\n';
        return 0;
    }
    for (int i = 1; i < n; i ++ )
    {
        int cnt = 0;
        VI pos;
        for (int j = 0; j < m; j ++ ) 
            if (a[0][j] != a[i][j])
            {
                pos.EB(j);
                cnt ++ ;
            }
        if (cnt <= 2) continue;
        else if (cnt == 3)
        {
            for (int x = 0; x < 3; x ++ )
                for (int y = 0; y < 3; y ++ )
                {
                    if (x == y) continue;
                    VI temp = a[0];
                    temp[pos[x]] = a[i][pos[x]];
                    if (check3(temp, pos[y]))
                    {
                        cout << "Yes\n";
                        for (auto &u : temp) cout << u << ' ';
                        cout << '\n';
                        return 0;
                    }
                }
        }
        else if (cnt == 4)
        {
            for (int x = 0; x < 4; x ++ )
                for (int y = x + 1; y < 4; y ++ )
                {
                    VI temp = a[0];
                    temp[pos[x]] = a[i][pos[x]];
                    temp[pos[y]] = a[i][pos[y]];
                    if (check4(temp))
                    {
                        cout << "Yes\n";
                        for (auto &u : temp) cout << u << ' ';
                        cout << '\n';
                        return 0;
                    }
                }
        }
        cout << "No\n";
        break;
    }
    return 0;
}

// GOOD LUCK!!!
