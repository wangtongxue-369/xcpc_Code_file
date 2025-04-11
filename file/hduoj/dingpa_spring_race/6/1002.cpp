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
ll _ = 1, n, m, ans = 0, a[MAXN], pre[MAXN];
ll ch;
bool check(ll x)
{
    ll k = x, p, l;
    deque<ll> q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && i - k + 1 > q.front())
        {
            q.pop_front();
        }
        while (!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (i < k)
        {
            continue;
        }
        l = i - k + 1;
        ll sum = 0;
        if (l - 1 >= 1)
        {
            sum += pre[l - 1] + abs(a[q.front()] - a[l - 1]);
        }
        if (i + 1 <= n)
        {
            sum += abs(a[i + 1] - a[q.front()]) + pre[n] - pre[i + 1];
        }
        if (sum <= ch)
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{
    ll x;
    cin >> n >> ch;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        pre[i] = abs(a[i] - a[i - 1]) + pre[i - 1];
    }
    ll l = 0, r = n;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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