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
bool cmp(string x, string y)
{
    if (stoll(x) <= stoll(y))
    {
        return 1;
    }
    return 0;
}
bool check(ll x, ll y)
{
    return cmp(to_string(x) + to_string(y), to_string(k));
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        ll l = 0, r = n;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            if (check(a[i], a[mid]))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (l >= i)
        {
            ans += l - 1;
        }
        else
        {
            ans += l;
        }
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
