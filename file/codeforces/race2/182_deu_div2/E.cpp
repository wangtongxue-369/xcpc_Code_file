/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll mp = 1;
    ll l1 = n, r1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[mp])
        {
            mp = i;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] == a[mp])
        {
            l1 = min(l1, i);
            r1 = max(r1, i);
        }
    }
    ans = 0;

    vector<ll> L;
    vector<ll> R;
    L.push_back(a[1]), R.push_back(a[n]);
    for (int i = 1; i <= l1; i++)
    {
        if (a[i] > L.back())
        {
            L.push_back(a[i]);
        }
    }
    for (int i = n; i >= r1; i--)
    {
        if (a[i] > R.back())
        {
            R.push_back(a[i]);
        }
    }
    R.pop_back();
    L.pop_back();
    // for (auto it : L)
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';
    // for (auto it : R)
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';
    vector<ll> c(n + 10); // 在L中与前i个匹配的子序列个数
    vector<ll> v(n + 10);
    vector<ll> dpl(n + 10);
    vector<ll> dpr(n + 10);
    dpl[0] = 1, dpr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = L.size(); j >= 1; j--)
        {
            if (a[i] > L[j - 1])
            {
                continue;
            }
            if (a[i] <= L[j - 1])
            {
                dpl[j] *= 2;
                dpl[j] %= mod;
            }
            if (a[i] == L[j - 1])
            {
                dpl[j] += dpl[j - 1];
                dpl[j] %= mod;
            }
        }
        c[i] = dpl[L.size()];
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = R.size(); j >= 1; j--)
        {
            if (a[i] > R[j - 1])
            {
                continue;
            }
            if (a[i] <= R[j - 1])
            {
                dpr[j] *= 2;
                dpr[j] %= mod;
            }

            if (a[i] == R[j - 1])
            {
                dpr[j] += dpr[j - 1];
                dpr[j] %= mod;
            }
        }
        v[i] = dpr[R.size()];
    }
    for (int i = l1; i <= r1; i++)
    {
        if (a[i] == a[mp])
        {
            ans += c[i] * v[i];
        }
        ans %= mod;
        for (int j = i + 1; j <= r1; j++)
        {
            if (a[i] == a[j] && a[j] == a[mp])
            {
                ans += (c[i] * v[j]) % mod * ksm(2, j - i - 1) % mod;
            }
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