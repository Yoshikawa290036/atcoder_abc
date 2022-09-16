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
    cin >> N;

    map<ll, vector<ll>> y_i;
    vector<int> y_list;
    ll x, y;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        y_i[y].push_back(i);
        if (y_i[y].size() == 2)
        {
            y_list.push_back(y);
        }
    }
    string str;
    cin >> str;
    if (y_list.size() == 0)
    {
        cout << "No" << endl;
        return 0;
    }
    for (size_t i = 0; i < y_list.size(); i++)
    {
        sort(all(y_i[y_list[i]]));
        bool flag1 = false, flag2 = false;
        for (size_t j = 0; j < y_i[y_list[i]].size(); j++)
        {
            if (!flag1 && str[y_i[y_list[i]][j]] == 'R')
            {
                flag1 = true;
                continue;
            }
            if (flag1)
            {
                if (str[y_i[y_list[i]][j]] == 'L')
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
