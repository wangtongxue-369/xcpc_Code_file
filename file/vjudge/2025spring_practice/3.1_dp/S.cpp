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
ll _ = 1, n, m, ans = 0, a[110], f[110];
PII road[110];
void solve()
{
    memset(f, INF, sizeof(f));
    memset(road, -1, sizeof(road));
    string t, s[15];
    cin >> t;
    ll m = t.length();
    t = ' ' + t;
    cin >> n;
    set<string> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    f[0] = 0;
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll len = i - (ll)s[j].length() + 1;
            if (len >= 1 && t.substr(len, s[j].length()) == s[j])
            {
                for (int k = i - s[j].length(); k < i; k++)
                {
                    if (f[i] > f[k] + 1)
                    {
                        f[i] = min(f[k] + 1, f[i]);
                        road[i].first = k;
                        road[i].second = j;
                    }
                }
            }
        }
    }
    if (f[m] > 1e18)
    {
        cout << -1 << '\n';
        return;
    }
    cout << f[m] << '\n';
    ll p = m;
    while (road[p].first != -1)
    {
        cout << road[p].second << ' ' << p - s[road[p].second].length() + 1 << '\n';
        p = road[p].first;
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
