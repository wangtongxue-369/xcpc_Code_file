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
ll _ = 1, n, m, ans = 1e19, a[MAXN], f[MAXN];
void solve()
{
    ll x, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    deque<ll> maxn, minn;
    for (int i = 1; i <= n; i++)
    {
        while (!maxn.empty() && i - k + 1 > maxn.back())
        {
            maxn.pop_back();
        }
        while (!maxn.empty() && a[maxn.front()] < a[i])
        {
            maxn.pop_front();
        }
        maxn.push_front(i);
        // cout << "big " << i << '\n';
        // cout << maxn.back() << '\n';
        // for (auto it : maxn)
        // {
        //     cout << it << ' ';
        // }
        // cout << '\n';
        while (!minn.empty() && i - k + 1 > minn.back())
        {
            minn.pop_back();
        }
        while (!minn.empty() && a[minn.front()] > a[i])
        {
            minn.pop_front();
        }
        minn.push_front(i);
        // cout << "small " << i << '\n';
        // for (auto it : minn)
        // {
        //     cout << it << ' ';
        // }
        // cout << '\n';
        if (i >= k)
        {
            ans = min(ans, a[maxn.back()] - a[minn.back()]);
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
