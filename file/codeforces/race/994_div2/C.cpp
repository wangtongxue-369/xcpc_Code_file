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
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> ans(n + 10, -1);
    queue<ll> q;
    q.push(x);
    ans[x] = 0;
    q.push(y);
    ans[y] = 1;
    while (!q.empty())
    {
        ll p = q.front();
        q.pop();
        ll l = p - 1;
        if (l == 0)
        {
            l = n;
        }
        ll r = p + 1;
        if (r == n + 1)
        {
            r = 1;
        }
        vector<ll> ve;
        if (ans[l] != -1)
        {
            ve.push_back(ans[l]);
        }
        else
        {
            q.push(l);
        }
        if (ans[r] != -1)
        {
            ve.push_back(ans[r]);
        }
        else
        {
            q.push(r);
        }
        if (p == x)
        {
            ve.push_back(1);
        }
        if (p == y)
        {
            ve.push_back(0);
        }
        sort(ve.begin(), ve.end());
        ll p1 = 0;
        for (auto it : ve)
        {
            if (it < p1)
            {
                continue;
            }
            if (it == p1)
            {
                p1++;
                continue;
            }
            break;
        }
        ans[p] = p1;
    }
    for (int i = 1; i <= n; i++)
    {

        cout << ans[i] << ' ';
    }
    cout << '\n';
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
