#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;

#define size_t ll
#define double long double
#define all(obj) (obj).begin(), (obj).end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define PI 3.141592653589793
const ll INF = 1e18;

template <int MOD>
struct Fp
{
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp &operator+=(const Fp &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
    {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept
    {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;

template <class T>
inline bool chmax(T &a, T b);
template <class T>
inline bool chmin(T &a, T b);
ll roundup(ll a, ll b); // 切り上げ
ll comb(ll n, ll r);    // nCr 組み合わせ
template <class T>
ll my_lower_bound(vector<T> &vec, T key); // vector配列のとき
// vector配列ではないとき int index = lower_bound(A, A + N, key) - A;

// ==================================================================== //
// ==================================================================== //
// ==================================================================== //
int a, N;
string Ns;
int Nssize;

inline ll sw(int n)
{
    ll x = n % 10;
    ll y = n / 10;
    string nw = to_string(x) + to_string(y);
    return stoll(nw);
}

inline bool isOK(ll &n)
{
    string ns = to_string(n);
    // cout << "isOK\t" << assize << "\t" << ns.size() << "\t\t";

    if (Nssize < ns.size())
    {
        return false;
    }
    return true;
}

int main()
{
    cin >> a >> N;
    Ns = to_string(N);
    Nssize = Ns.size();

    queue<pair<int, int>> q;
    map<int, int> mp;
    q.push(make_pair(1, 0));

    while (!q.empty())
    {
        pair<int, int> t = q.front();
        cout << t.first << "\t" << t.second << endl;
        q.pop();
        if (mp[t.first])
        {
            continue;
        }
        mp[t.first]++;
        ll nf = a * t.first;
        if (isOK(nf))
        {
            // cout << "aaa" << '\t';
            if (nf == N)
            {
                cout << t.second + 1 << endl;
                return 0;
            }
            else
            {
                q.push(make_pair(nf, t.second + 1));
                // cout << nf << endl;
            }
        }

        if (t.first / 10 > 1 && t.first % 10 != 0)
        {
            ll nsf = sw(t.first);
            if (nsf == N)
            {
                cout << t.second + 1 << endl;
                return 0;
            }
            if (!isOK(nsf))
            {
                continue;
            }
            else
            {
                q.push(make_pair(nsf, t.second + 1));
            }
        }
    }
    cout << -1 << endl;

    return 0;
}

// ==================================================================== //
// ==================================================================== //
// ==================================================================== //

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

ll roundup(ll a, ll b)
{
    return ((a + b - 1) / b);
}

ll comb(ll n, ll r)
{
    if (r < 1 || n < r)
        return 0;
    double ans = 1.0;
    for (size_t i = 1; i <= r; i++)
        ans *= (double)(n - i + 1) / (double)(i);
    return (ll)ans;
}

template <class T>
ll my_lower_bound(vector<T> &vec, T key)
{
    auto it = lower_bound(all(vec), key);
    return (it - vec.begin());
}
