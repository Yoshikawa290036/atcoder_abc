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
ll my_lower_bound(vector<T> &vec, T key); // vector配列のとき
// vector配列ではないとき int index = lower_bound(A, A + N, key) - A;

// ==================================================================== //

int start, eee;

bool dfs(int &sss, vector<vector<ll>> &gp, vector<bool> &visit)
{
    visit[sss] = true;
    if (sss == eee)
    {
        return true;
    }

    for (int nc : gp[sss])
    {
        if (visit[nc])
        {
            continue;
        }

        if (dfs(nc, gp, visit))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ll N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    vector<vector<ll>> gp(N);
    vector<ll> x(N), y(N), r(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            ll d2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (d2 > (r[i] + r[j]) * (r[i] + r[j]) || d2 < (r[i] - r[j]) * (r[i] - r[j]))
            {
                continue;
            }
            gp[i].push_back(j);
            gp[j].push_back(i);
        }
    }
    vector<bool> visit(N, false);

    for (size_t i = 0; i < N; i++)
    {
        if ((x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy) == r[i] * r[i])
        {
            start = i;
        }
        if ((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty) == r[i] * r[i])
        {
            eee = i;
        }
    }
    // cout << endl;
    // cout << start << endl;
    // cout << eee << endl;
    visit[start] = true;
    if (dfs(start, gp, visit))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
