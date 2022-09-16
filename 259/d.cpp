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

int main()
{
    ll N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<vector<ll>> gp(N, vector<ll>(3));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin >> gp[i][j];
        }
    }

    queue<vector<ll>> que;
    vector<bool> visit(N, false);

    for (size_t i = 0; i < N; i++)
    {
        if (gp[i][2] * gp[i][2] == (gp[i][0] - sx) * (gp[i][0] - sx) + (gp[i][1] - sy) * (gp[i][1] - sy))
        {
            que.push(gp[i]);
            visit[i] = true;

        }
    }

    while (!que.empty())
    {
        vector<ll> top = que.front();
        que.pop();

    }

    cout << "No" << endl;
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
