#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ans = 0;
    ll x, p, k, cnt;
    cin >> n >> k;
    for (ll i = 2; i <= min(k, n); i++)
    {
        ll sum = 0;
        p = 1;
        x = n;
        cnt = 0;
        queue<ll> q;
        while (p <= x)
        {
            p *= i;
        }
        p /= i;
        while (x)
        {

            q.push(x / p);

            x %= p;
            p /= i;
        }
        ll len = q.size();
        // if (i == 2)
        // {
        //     for (int j = 1; j <= len; j++)
        //     {
        //         cout << q.front() << ' ';
        //         q.push(q.front());
        //         q.pop();
        //     }
        //     cout << '\n';
        // }

        p = 1;
        while (q.size())
        {
            sum += p * q.front();
            p *= i;
            q.pop();
        }
        ans += sum;
        ans %= mod;
    }
    if (k > n)
    {
        __int128_t t = ((__int128_t)n * (__int128_t)(k - n)) % (__int128_t)mod;
        ans = (ans + t) % mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
