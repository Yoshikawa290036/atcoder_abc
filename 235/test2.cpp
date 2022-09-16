#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 1000000007, INF = -1;

ll keta(ll a)
{
    ll now = 1;
    while (true)
    {
        if (a < pow(10, now))
        {
            return now;
        }
        now++;
    }
}

int main()
{
    ll A, N;
    cin >> A >> N;
    ll MAX = pow(10, keta(N));

    vector<ll> num(MAX + 1, INF);
    num[1] = 0;

    queue<ll> que;
    que.push(1);
    while (!que.empty())
    {
        ll tar = que.front();
        que.pop();

        ll next = tar * A;
        if (next <= MAX)
        {
            if (num[next] == INF)
            {
                num[next] = num[tar] + 1;
                que.push(next);
            }
        }

        if (tar >= 10 && tar % 10 != 0)
        {
            ll next2 = tar / 10 + (tar % 10) * pow(10, keta(tar) - 1);
            if (next2 <= MAX)
            {
                if (num[next2] == INF)
                {
                    num[next2] = num[tar] + 1;
                    que.push(next2);
                }
            }
        }
    }

    cout << num[N] << endl;
}
