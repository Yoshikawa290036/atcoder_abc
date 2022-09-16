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

void core(string str, vector<pair<char, ll>> &vec)
{
    pair<char, ll> ans;
    char pre = str[0];
    ll count = 1;
    for (size_t i = 1; i < str.size(); i++)
    {
        if (pre == str[i])
        {
            count++;
        }
        else
        {

            vec.push_back(make_pair(pre, count));
            count = 1;
            pre = str[i];
        }
    }
}

int main()
{
    string s, t, ns, nt;
    cin >> s;
    cin >> t;
    // cout << core(s) << endl;
    // cout << core(t) << endl;

    vector<pair<char, ll>> ss, ts;
    core(s + '#', ss);
    core(t + '#', ts);

    // for (size_t i = 0; i < ss.size(); i++)
    // {
    //     cout << ss[i].first << ' ' << ss[i].second << endl;
    // }

    if (ss.size() != ts.size())
    {
        cout << "No" << endl;
        return 0;
    }

    for (size_t i = 0; i < ss.size(); i++)
    {
        if (ss[i].first != ts[i].first)
        {
            cout << "No" << endl;
            return 0;
        }
        ll sss = ss[i].second;
        ll ttt = ts[i].second;

        if (sss > ttt)
        {
            cout << "No" << endl;
            return 0;
        }
        if (sss < ttt)
        {
            if (sss == 1)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

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
