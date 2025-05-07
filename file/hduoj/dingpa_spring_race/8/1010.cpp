#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e4 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll B(string s)
{
    ll res{0}, k{1};
    for (ll i = 0; i < s.size(); i++)
    {
        res += (s[i] - 'a' + 1) * k;
        k *= 10;
    }
    return res % mod;
}

void solve()
{
    ll k, c, d, e, f;
    ans = 0;
    cin >> k >> c >> d >> e >> f;
    for (ll i = 0; i < mod; i++)
    {
        ll x = i * i * i * c + i * i * d + i * e + f;
        string s;
        bool ok = 1;
        while (x)
        {
            s += (char)(x % 27 + 'a' - 1);
            if (s.back() < 'a' || s.back() > 'z')
            {
                ok = false;
                break;
            }
            x /= 27;
        }
        if (!ok)
        {
            continue;
        }

        if (!s.empty() && s.size() <= k && B(s) == i)
        {
            ans++;
        }
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