/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
vector<vector<ll>> ve(200050);
void solve()
{
    ll k;
    cin >> n >> k;
    vector<ll> vis(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        ll p = max(1ll, a[i] / 4);
        for (auto it : ve[a[i]])
        {
            if (it <= p)
            {
                continue;
            }
            // kexing
            vis[it]++;
            // bukexing
            vis[it + 1]--;
        }
        vis[p + 1]--;
    }
    ans = 1;
    ll p = n;
    for (ll i = 2; i <= n; i++)
    {
        p += vis[i];
        if (p + k >= n)
        {
            ans = max(ans, i);
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= 200010; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j != 0)
            {
                continue;
            }
            ve[i].push_back(j);
            if (j * j != i)
            {
                ve[i].push_back(i / j);
            }
        }
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}