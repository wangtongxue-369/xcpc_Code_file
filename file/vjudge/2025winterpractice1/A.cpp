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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    ll f;
    string s;
} a[MAXN];
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].f >> a[i].s;
    }
    ll op, s;
    ll p = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> s;
        // shun -
        // ni +
        if (a[p].f == 0)
        {
            if (op == 0)
            {
                p = ((p - s) % n + n) % n;
            }
            else
            {
                p = (p + s) % n;
            }
        }
        else
        {
            if (op == 0)
            {
                p = (p + s) % n;
            }
            else
            {
                p = ((p - s) % n + n) % n;
            }
        }
    }
    cout << a[p].s;
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
