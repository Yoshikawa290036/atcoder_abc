#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define size_t ll
#define double long double
#define all(obj) (obj).begin(), (obj).end()
const double PI = 3.141592653589793;
const ll INF = 1e18, MOD = 1000000007;
template <class T>
inline bool chmax(T &a, T b);
template <class T>
inline bool chmin(T &a, T b);
ll roundup(ll a, ll b); // 切り上げ
ll comb(ll n, ll r);    // nCr 組み合わせ
template <class T>
ll my_lower_bound(vector<T> &vec, T key);

// ==================================================================== //

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    // x += 1000;
    // y += 1000;
    // z += 1000;

    if (x * y < 0)
    {
        cout << x << endl;
        return 0;
    }
    if (abs(x) < abs(y))
    {
        cout << x << endl;
        return 0;
    }

    int ans = 0;
    if (y * z < 0)
    {
        ans += abs(z) * 2;
        ans += abs(x);
        cout << ans << endl;
        return 0;
    }
    else
    {
        if (abs(y) < abs(z))
        {
            cout << -1 << endl;
            return 0;
        }
        cout << x << endl;
    }

    return 0;
}

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
