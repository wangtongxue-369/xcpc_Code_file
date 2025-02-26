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
    ll k;
    cin >> k;
    vector<PII> ve;
    ans = 0;
    ll x = 0;
    vector<ll> s;
    if (k == 0)
    {
        cout << 0 << '\n';
        return;
    }
    while (k > 0)
    {
        // cout << k << endl;
        ll p = 0;
        for (ll i = 2; i <= 1000; i++)
        {
            if (((i * (i - 1)) / 2) <= k)
            {
                continue;
            }
            else
            {
                p = i;
                break;
            }
        }
        p--;
        k -= (p * (p - 1)) / 2;
        s.push_back(p);
    }
    // for (auto it : s)
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';

    x = 0;
    ll y = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x++;
        y++;
        for (int j = 1; j <= s[i]; j++)
        {
            ve.push_back({x, y});
            y++;
            // cout << x << ' ' << y << '\n';
        }
    }
    cout << ve.size() << '\n';
    for (auto it : ve)
    {
        cout << it.first << ' ' << it.second << '\n';
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
