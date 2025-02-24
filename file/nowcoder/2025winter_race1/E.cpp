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
ll _ = 1, n, m, a[MAXN], f[MAXN];
ll ff(vector<ll> ve)
{
    sort(ve.begin(), ve.end());
    ll sum = 0;
    for (int i = 0; i < ve.size(); i++)
    {
        sum += abs(ve[0] - ve[i]);
    }
    ll ans = sum;
    ll p = ve[0];
    for (int i = 0; i < ve.size() - 1; i++)
    {
        cout << '!' << i << ' ' << (ve[i + 1] - ve[i]) << '\n';
        cout << (ve.size() - (i + 1)) << '\n';
        sum -= (ve.size() - (i + 1)) * (ve[i + 1] - ve[i]);
        sum += (i + 1) * (ve[i + 1] - ve[i]);
        ans = min(ans, sum);
    }
    return ans;
}
void solve()
{
    cin >> n;
    map<ll, ll> ma;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 1e18;
    ll left = a[(n / 2) / 2], right = a[n / 2 + (n / 2) / 2];

    for (auto x : {left - 1, left, left + 1})
    {
        for (auto y : {right - 1, right, right + 1})
        {
            if (x == y)
            {
                continue;
            }
            ll sum = 0;
            for (int i = 0; i < n / 2; i++)
            {
                sum += abs(a[i] - x);
                sum += abs(a[n / 2 + i] - y);
            }
            ans = min(ans, sum);
        }
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
