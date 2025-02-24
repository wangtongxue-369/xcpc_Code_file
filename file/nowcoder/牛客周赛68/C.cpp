#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n;
    map<ll, ll> ma1, ma2, U;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = x;
        ma1[x]++;
        U[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        b[i] = x;
        ma2[x]++;
        U[x]++;
    }
    ll sum1 = 0, sum2 = 0;
    for (auto &[x, y] : U)
    {
        if (y >= 2)
        {
            if (ma1.count(x))
            {
                sum1 += ma1[x] - 1;
            }
            if (ma2.count(x))
            {
                sum2 += ma2[x] - 1;
            }
        }
    }
    ll sum = 0;
    for (auto &[x, y] : U)
    {
        if (y >= 2 && ma1.count(x) && ma2.count(x))
        {
            if (sum1 > sum2)
            {
                sum2++;
            }
            else if (sum1 < sum2)
            {
                sum1++;
            }
            else
            {
                sum++;
            }
        }
    }
    ans = 0;
    if (sum1 == sum2)
    {
        ans = sum1 + (sum + 1) / 2;
    }
    else
    {
        ans = max(sum1, sum2);
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
