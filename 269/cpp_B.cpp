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
    int a = 0, b = 0, c = 0, d = 0;

    vector<string> strs(10);
    string str;
    string nothing = "..........";
    for (size_t i = 0; i < 10; i++)
    {
        cin >> strs[i];
    }

    for (size_t i = 1; i < 11; i++)
    {
        str = strs[i - 1];
        if (str == nothing)
        {
            // cout << i << endl;
            if (a != 0 && b == 0)
            {
                b = i - 1;
            }
        }
        else
        {
            if (a == 0)
            {
                a = i;
                for (size_t j = 1; j < 11; j++)
                {
                    if (str[j - 1] == '#' && c == 0)
                    {
                        c = j;
                    }
                    if (str[j - 1] == '.' && c != 0 && d == 0)
                    {
                        d = j - 1;
                    }
                }
            }
        }
    }
    if (b == 0)
    {
        b = 10;
    }
    if (d == 0)
    {
        d = 10;
    }


    cout << a << ' ' << b << endl;
    cout << c << ' ' << d << endl;

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
