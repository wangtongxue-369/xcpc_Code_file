#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
ll gcd(ll a, ll b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
void solve()
{
    cin >> n;
    vector<ll> f(n + 10, 0), ha(n + 10, -1);
    vector<ll> a(n + 10);
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    auto check = [&](int g, int a1) -> int
    {
        int b = a1 + g;
        if (b <= n && gcd(a1, b) == g)
            return f[b];
        return 0;
    };
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ha[a[i]] >= 0)
        {
            ans += ha[a[i]];
            continue;
        }
        ll res = 0;
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                res += check(j, a[i]);
                if (a[i] / j != j)
                {
                    res += check(a[i] / j, a[i]);
                }
            }
        }
        ha[a[i]] = res;
        ans += res;
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