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
struct node
{
    ll r, w;
} b[MAXN];
bool cmp(node s1, node s2)
{
    return s1.r < s2.r;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].r >> b[i].w;
    }
    sort(b + 1, b + 1 + m, cmp);
    ll p = 1;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 1; i <= m; i++)
    {
        while (p <= n && p <= b[i].r)
        {
            q.push(a[p]);
            p++;
        }
        if (q.size())
        {
            ll x = q.top();
            q.pop();
            q.push(x - b[i].w);
        }
    }
    while (p <= n)
    {
        q.push(a[p]);
        p++;
    }
    ll sum = 0;
    while (q.size())
    {
        sum += q.top();
        cout << sum << ' ';
        q.pop();
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