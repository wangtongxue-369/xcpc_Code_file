#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // start[500005], en[500005];
void solve()
{
    ll d, k;
    cin >> n >> d >> k;
    ll l, r;
    // memset(start, 0, sizeof(start));
    // memset(en, 0, sizeof(en));
    vector<ll> start(n + 10);
    vector<ll> en(n + 10);
    for (int i = 1; i <= k; i++)
    {
        cin >> l >> r;
        start[l]++;
        en[r]++;
    }
    ll s = 0;
    start[0] = 0;
    start[n + 1] = 0;
    en[0] = 0;
    en[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        start[i] += start[i - 1];
        en[i] += en[i - 1];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    // deque<int> q;
    ll ans1 = 0, ans2 = 0;
    ll sum1 = 0, sum2 = 1e18;
    ll sum = 0;
    for (int i = d; i <= n; i++)
    {
        sum = start[i] - en[i - d];
        if (sum > sum1)
        {
            ans1 = i - d + 1;
            sum1 = sum;
        }
        if (sum < sum2)
        {
            ans2 = i - d + 1;
            sum2 = sum;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
