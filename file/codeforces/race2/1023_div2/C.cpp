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
void cans()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
void solve()
{
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll sum0 = 0;
    ll p0 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            sum0++;
            p0 = i;
            a[i] = -1e17;
        }
    }
    ll ps = 0, maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        ps = max(ps + a[i], a[i]);
        maxn = max(maxn, ps);
    }
    // cout << maxn << '\n';
    if (maxn == k)
    {
        cout << "Yes\n";
        cans();
        return;
    }
    if (maxn > k)
    {
        cout << "No\n";
        return;
    }
    if (maxn < k && p0 == 0)
    {
        cout << "No\n";
        return;
    }
    ll ps1 = 0, ps2 = 0;
    for (int i = 1; i < p0; i++)
    {
        ps1 = max(ps1 + a[i], a[i]);
    }
    for (int i = n; i > p0; i--)
    {
        ps2 = max(ps2 + a[i], a[i]);
    }
    a[p0] = k - (max(ps1, 0ll) + max(ps2, 0ll));
    cout << "Yes\n";
    cans();
}
// 用-1e18可以把数字强制隔开
// 如果没有，那只能直接看最大值
// 1个
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