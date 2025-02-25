#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 1, r = 1;
    ll ansl = 1, ansr = n;
    ans = 1e18;
    ll sum = 0;
    map<ll, ll> ma;
    for (r = 1; r <= n; r++)
    {
        ma[a[r]]++;
        if (ma[a[r]] == 1)
        {
            sum++;
        }
        while (sum == m)
        {
            if ((r - l + 1) < ans)
            {
                ansl = l, ansr = r;
                ans = (r - l + 1);
            }
            if (ma[a[l]] == 1)
            {
                sum--;
            }
            ma[a[l]]--;
            l++;
        }
    }
    cout << ansl << ' ' << ansr << '\n';
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
