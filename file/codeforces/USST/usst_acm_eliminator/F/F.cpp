#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 998244353;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0;
vector<ll> prime;
bool f[1000000 + 100];
ll c[1000000 + 100];
void Prime(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (!f[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= x; j++)
        {
            f[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        ll x = l - 1, j = 0;
        while (x)
        {
            x /= prime[i];
            c[j] = x;
            if (j != 0)
            {
                c[j - 1] = ((c[j - 1] - x) % mod + mod) % mod;
            }
            j++;
        }
        ll tmp = 0;
        for (int k = 0; k < j; k++)
        {
            tmp = (tmp + ((c[k] * prime[i]) % mod * k) % mod) % mod;
        }
        ans1 = (ans1 + tmp) % mod;
    }
    for (int i = 0; i < prime.size(); i++)
    {
        ll x = r, j = 0;
        while (x)
        {
            x /= prime[i];
            c[j] = x;
            if (j != 0)
            {
                c[j - 1] = ((c[j - 1] - x) % mod + mod) % mod;
            }
            j++;
        }
        ll tmp = 0;
        for (int k = 0; k < j; k++)
        {
            tmp = (tmp + ((c[k] * prime[i]) % mod * k) % mod) % mod;
        }
        ans2 = (ans2 + tmp) % mod;
    }
    cout << ((ans2 - ans1) % mod + mod) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Prime(1000000);
    // for (int i = 0; i < prime.size(); i++)
    // {
    //     cout << prime[i] << '\n';
    // }
    // cout << prime.size() << '\n';
    cin >> _;

    while (_--)
    {
        solve();
    }
    return 0;
}
