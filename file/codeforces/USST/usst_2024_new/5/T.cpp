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
vector<ll> sum1(MAXN + 10, 0), sum0(MAXN + 10, 0);
bool check(ll x, ll i)
{
    ll s1 = sum1[i] + (sum1[n] - sum1[x]);
    ll s0 = sum0[x] - sum0[i];
    if (s0 <= s1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    string s;
    cin >> s;
    n = s.length();
    s = ' ' + s;
    sum1[n + 1] = 0, sum0[n + 1] = 0;
    sum1[n + 2] = 0, sum0[n + 2] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum1[i] = sum1[i - 1] + (s[i] == '1' ? 1 : 0);
        sum0[i] = sum0[i - 1] + (s[i] == '0' ? 1 : 0);
    }
    // cout << '\n';
    ans = 1e18;
    for (int i = 0; i <= n; i++)
    {
        ll l = i + 1, r = n;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            if (check(mid, i))
                l = mid;
            else
                r = mid - 1;
        }
        // cout << i + 1 << ' ' << l << '\n';
        ans = min(ans, max(sum1[i] + sum1[n] - sum1[l], sum0[l] - sum0[i]));
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
