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

// =============================================================================== //
// =============================================================================== //
// =============================================================================== //

int main()
{
    ll N;
    cin >> N;
    char tmp;
    vector<vector<bool>> field(N, vector<bool>(N, false));

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp == '#')
            {
                field[i][j] = true;
            }
            else
            {
                field[i][j] = false;
            }
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            int col = 1, row = 1, dia1 = 1, dia2 = 1;
            if (!field[i][j])
            {
                continue;
            }
            else
            {
                if (i + 5 < N)
                {
                    for (size_t k = 1; k < 6; k++)
                    {
                        if (field[i + k][j])
                        {
                            col++;
                        }
                    }
                }

                if (j + 5 < N)
                {
                    for (size_t k = 1; k < 6; k++)
                    {
                        if (field[i][j + k])
                        {
                            row++;
                        }
                    }
                }

                if (i + 5 < N && j + 5 < N)
                {
                    for (size_t k = 1; k < 6; k++)
                    {
                        if (field[i + k][j + k])
                        {
                            dia1++;
                        }
                    }
                }

                if (i + 5 < N && j - 5 >= 0)
                {
                    for (size_t k = 0; k < 6; k++)
                    {
                        if (field[i + k][j - k])
                        {
                            dia2++;
                        }
                    }
                }

                if (col >= 4 || row >= 4 || dia1 >= 4 || dia2 >= 4)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

// =============================================================================== //
// =============================================================================== //
// =============================================================================== //

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
