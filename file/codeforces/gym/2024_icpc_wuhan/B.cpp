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
    cin >> n;
    ll sum = 0;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += x;
    }
    vector<ll> b(100, 0);
    ans = 0;
    b[0] = sum;
    ll cnt = sum;
    a[0] = sum;
    ll i = 0;
    while (cnt > n)
    {
        if (cnt - a[i] / 2 > n)
        {
            cnt -= a[i] / 2;
            a[i + 1] = a[i] / 2;
            a[i] %= 2;
        }
        else
        {
            a[i + 1] = cnt - n;
            a[i] -= (cnt - n) * 2;
            cnt = n;
        }
        i++;
    }
    ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans |= a[i];
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
