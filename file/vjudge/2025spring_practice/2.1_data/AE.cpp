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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    set<ll> se;
    vector<ll> a;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        se.insert(x);
        a.push_back(x);
    }
    if (k >= 3)
    {
        cout << 0 << '\n';
        return;
    }
    if (k == 1)
    {
        sort(a.begin(), a.end());
        ans = LONG_LONG_MAX;
        ans = a[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, a[i]);
            ans = min(ans, abs(a[i] - a[i + 1]));
        }
        cout << ans << '\n';
        return;
    }
    if (k == 2)
    {
        ans = 2e18;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ll tmp = abs(a[i] - a[j]);
                ans = min(ans, tmp);
                auto it = lower_bound(a.begin(), a.end(), tmp) - a.begin();
                if (it < n)
                {
                    ans = min(ans, abs(tmp - a[it]));
                }
                if (it > 0)
                {
                    ans = min(ans, abs(tmp - a[it - 1]));
                }
            }
        }
        cout << ans << '\n';
    }
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
