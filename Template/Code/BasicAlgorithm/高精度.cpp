// 完整大整数类
// 注意除法效率以及除以小整数时爆 int 的问题
struct BigInteger
{
    static const int BASE = 10000;
    static const int WIDTH = 4;
    vector<int> s;
    int flag = 1;
    
    BigInteger(int num = 0) { *this = num; }

    BigInteger(string str) { *this = str; }

    BigInteger(const BigInteger &t)
    {
        this->flag = t.flag;
        this->s = t.s;
    }

    BigInteger operator= (int num)
    {
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }

    BigInteger operator= (string &str)
    {
        s.clear();
        int x, len = ((int)str.size() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i ++ )
        {
            int end = (int)str.size() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    bool cmp(vector<int> &A, vector<int> &B)
    {
        int na = A.size(), nb = B.size();
        if (na != nb) return na < nb;
        for (int i = na - 1; i >= 0; i -- )
            if (A[i] != B[i])
                return A[i] < B[i];
        return false;
    }

    bool operator< (BigInteger &b) { return cmp(s, b.s); }
    bool operator> (BigInteger &b) { return b < *this; }
    bool operator<= (BigInteger &b) { return !(b < *this); }
    bool operator>= (BigInteger &b) { return !(*this < b); }
    bool operator== (BigInteger &b) { return !(b < *this) && (*this < b); }

    vector<int> add(vector<int> &A, vector<int> &B);
    vector<int> sub(vector<int> &A, vector<int> &B);
    vector<int> mul(vector<int> &A, int b);
    vector<int> mul(vector<int> &A, vector<int> &B);
    vector<int> div(vector<int> &A, int b);
    vector<int> div(vector<int> A, vector<int> B);

    BigInteger operator+ (BigInteger &b);
    BigInteger operator- (BigInteger &b);
    BigInteger operator* (BigInteger &b);
    BigInteger operator* (int b);
    BigInteger operator/ (BigInteger & b);
    BigInteger operator/ (int b);
};

ostream& operator<< (ostream &out,const BigInteger& x)
{
    if (x.flag == -1) out << '-';
    out << x.s.back();
    for (int i = (int)x.s.size() - 2; i >= 0; i -- )
    {
        char buf[20];
        // 4 is the same as WIDTH
        sprintf(buf,"%04d",x.s[i]);
        for (int j = 0; j < strlen(buf); j ++ )
            out << buf[j];
    }
    return out;
}

istream& operator>> (istream & in,BigInteger &x)
{
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}

vector<int> BigInteger::add(vector<int> &A, vector<int> &B){
    int na = A.size(), nb = B.size();
    if (na < nb) return add(B, A);
    int t = 0;
    vector<int> C;
    for (int i = 0; i < na; i ++ )
    {
        if(i < nb)t += B[i];
        t += A[i];
        C.push_back(t % BASE);
        t /= BASE;
    }
    if (t) C.push_back(t);
    while ((int)C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> BigInteger::sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int na = A.size(), nb = B.size();
    for (int i = 0, t = 0; i < na; i ++ )
    {
        t = A[i] - t;
        if (i < nb) t -= B[i];
        C.push_back((t + BASE) % BASE);
        if (t < 0) t = 1;
        else t = 0;
    }
    while ((int)C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
vector<int> BigInteger::mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0, na = A.size();
    for (int i = 0; i < na || t; i ++ )
    {
        if(i < na) t += A[i] * b;
        C.push_back(t % BASE);
        t /= BASE;
    }
    return C;
}

vector<int> BigInteger::mul(vector<int> &A, vector<int> &B)
{
    int na = A.size(), nb = B.size();
    vector<int> C(na + nb);
    for (int i = 0; i < na; i ++ )
        for (int j = 0; j < nb; j ++ )
        {
            C[i + j] += A[i] * B[j];
            C[i + j + 1] += C[i + j] / BASE;
            C[i + j] %= BASE;
        }
    while ((int)C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> BigInteger::div(vector<int> &A, int b)
{
    vector<int> C;
    int r = 0, na = A.size();
    for (int i = na - 1;i >= 0; i -- )
    {
        r = r * BASE + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> BigInteger::div(vector<int> A, vector<int> B)
{
    int na = A.size(), nb = B.size();
    int dv = na - nb;
    vector<int> C(dv + 1, 0);
    reverse(B.begin(), B.end());
    for (int i = 0; i < dv; i ++ ) B.push_back(0);
    reverse(B.begin(), B.end());
    nb = na;
    for (int j = 0; j <= dv; j ++ )
    {
        while(!cmp(A, B))
        {
            A = sub(A, B);
            C[dv - j] ++ ;
        }
        B.erase(B.begin());
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

BigInteger BigInteger::operator+ (BigInteger &b)
{
    BigInteger c;
    c.s.clear();
    c.s = add(s, b.s);
    return c;
}

BigInteger BigInteger::operator- ( BigInteger &b) {
    BigInteger c;
    c.s.clear();
    if (*this < b)
    {
        c.flag = -1;
        c.s = sub(b.s, s);
    }
    else
    {
        c.flag = 1;
        c.s = sub(s, b.s);
    }
    return c;
}

BigInteger BigInteger::operator* (BigInteger & b)
{
    BigInteger c;
    c.s = mul(s, b.s);
    return c;
}

BigInteger BigInteger::operator* (int b)
{
    BigInteger c;
    c.s = mul(s, b);
    return c;
}

BigInteger BigInteger::operator/ (BigInteger &b)
{
    BigInteger c;
    if (*this < b) return c;
    else
    {
        c.flag = 1;
        c.s = div(s, b.s);
    }
    return c;
}

BigInteger BigInteger::operator/ (int b)
{
    BigInteger c;
    BigInteger t = b;
    if (*this < t) c.s.push_back(0);
    else
    {
        c.flag = 1;
        c.s = div(s, b);
    }
    return c;
}

using Bint = BigInteger;



// 简单大整数实现
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// C = A * b, A >= 0, b > 0
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

vector<int> mul(vector<int> A, vector<int> B)
{
    vector<int> C((int)A.size() + (int)B.size());
    for (int i = 0; i < (int)A.size(); i ++ )
        for (int j = 0; j < (int)B.size(); j ++ )
        {
            C[i + j] += A[i] * B[j];
            C[i + j + 1] += C[i + j] / 10;
            C[i + j] %= 10;
        }
    while ((int)C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
