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
ll k;
string s;
bool check(ll x)
{
    ll res = 0;
    for (int i = 1; i <= n - m + 1; i++)
    {
    }
}
void solve()
{
    cin >> n >> m >> k;
    s.clear();
    cin >> s;
    s = ' ' + s;
    vector<ll> pre(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : 0);
    }
    ans = 0;
    for (int i = m; i <= n; i++)
    {
        ll s1 = pre[i] - pre[i - m];
        if (s1 != 0)
        {
            continue;
        }
        else
        {
            ans++;
            i = i + k + m - 1 - 1;
        }
    }
    cout << ans << '\n';
    // ll l=0,r=1e9;
    // while (l<r)
    // {
    //     ll mid=(l+r)>>1;
    //     if (check(mid)) r=mid;
    //     else l=mid+1;
    // }
    // cout<<l<<'\n';
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
