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
ll _ = 1, n, m, ans = 0, a[1000000 + 10]; // f[MAXN];
ll mfrist[1000000 + 10];
ll ma[1000000 + 10];
bool vis[1000000 + 10];
bool vis2[1000000 + 10];
void solve()
{
    cin >> n;
    ll sum0 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mfrist[a[i]] = 0;
        vis[a[i]] = 0;
        ma[a[i]] = 0;
        vis2[a[i]] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mfrist[a[i]] == 0)
        {
            mfrist[a[i]] = i;
        }
    }
    vector<ll> f(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + (a[i] == 0);
    }
    ans = 0;
    vector<PII> ve;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        if (vis[a[i]])
        {
            continue;
        }
        if (ma[a[i]] == 0)
        {
            ma[a[i]]++;
        }
        else
        {
            if (f[i] - f[mfrist[a[i]] - 1] > 0)
            {
                ve.push_back({i, a[i]});
                vis[a[i]] = 1;
            }
        }
    }
    ll i = n + 1;
    reverse(ve.begin(), ve.end());
    ll sum = 0;
    map<ll, ll> m1;
    for (auto it : ve)
    {
        // cout << it.first << ' ' << it.second << '\n';
        while (i > it.first + 1)
        {
            i--;
            if (a[i] == 0)
            {
                continue;
            }
            if (vis2[a[i]] == 0)
            {
                sum++;
                vis2[a[i]] = 1;
            }
        }
        ans += (sum);
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