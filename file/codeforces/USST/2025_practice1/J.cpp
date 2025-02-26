#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mo = 1e9 + 1;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], d[MAXN];
void solve()
{
    ll s1, s2;
    cin >> n >> s1 >> s2;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    queue<ll> l, r;
    ll cs = min(s1, s2) / n;
    s1 -= cs * n;
    s2 -= cs * n;
    // 每2*(1e9+1)次时间后，
    // 每个挡板被撞n次，并且所有小球回到原点
    // cs 就是在最后一次之前有几轮
    ll t = cs * (2 * mo);
    // cout << t << '\n';
    ll pret = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 1; i <= n; i++)
    {
        // cout << d[i] << ' ';
        if (d[i] == 0)
        {
            q.push({a[i], 0});
        }
        else
        {
            q.push({mo - a[i], 1});
        }
    }
    // cout << s1 << ' ' << s2 << '\n';
    ans = 0;
    while (q.size())
    {
        auto [p, dir] = q.top();
        q.pop();
        ans = p;
        // cout << p << '\n';
        if (dir == 0)
        {
            if (s1)
            {
                s1--;
                q.push({mo + p, 1});
            }
        }
        else
        {
            if (s2)
            {
                s2--;
                q.push({mo + p, 0});
            }
        }
    }
    // cout << ans << '\n';
    cout << ans + t;
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
