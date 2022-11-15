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
    ll N;
    cin >> N;

    vector<ll> od, ev;
    ll x;

    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        if (x % 2)
        {
            od.push_back(x);
        }
        else
        {
            ev.push_back(x);
        }
    }
    if (N == 2)
    {
        if (od.size() == 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    sort(all(od));
    sort(all(ev));

    ll odod = -INF, evev = -INF;

    if (od.size() > 1)
    {
        odod = od[od.size() - 1] + od[od.size() - 2];
    }
    if (ev.size() > 1)
    {
        evev = ev[ev.size() - 1] + ev[ev.size() - 2];
    }
    cout << max(odod, evev) << endl;

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
