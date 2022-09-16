#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define size_t ll
#define double long double
#define all(obj) (obj).begin(), (obj).end()
const double PI = 3.141592653589793;
const ll INF = 1e18, MOD = 998244353;
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
    int n, m, k, s, t, x;
    int u, v;
    cin >> n >> m >> k >> s >> t >> x;
    vector<vector<int>> gp(n + 1);
    for (size_t i = 0; i < m; i++)
    {
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    ll ans = 0;
    queue<int> que;
    que.push(s);
    vector<ll> vst(n + 1, -1);
    vst[s] == 0;
    int step = 0;
    while (!que.empty())
    {
        int pos = que.front();
        que.pop();
        for (int npos : gp[pos])
        {
            if (vst[npos] != -1)
            {
                continue;
            }
            if (npos == t)
            {
                break;
            }
            vst[npos] = vst[pos] + 1;
            que.push(npos);
        }
    }

    if (vst[t] == -1 || vst[t] > k)
    {
        cout << 0 << endl;
        return 0;
    }

    int x = vst[t] - 2;
    if (x == 0)
    {
        ans = 1;
    }
    else
    {
        int y = x - k;

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
