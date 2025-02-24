#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // a[N], b[N];
struct node
{
    ll a, b, i;
} a[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].b;
        a[i].i = i;
    }
    ans = 1e10;
    for (int j = 2; j <= n - 1; j++)
    {
        ll s1 = 1e10, s2 = 1e10;
        for (int i = 1; i < j; i++)
        {
            if (a[i].a < a[j].a)
            {
                s1 = min(s1, a[i].b);
            }
        }
        for (int i = j + 1; i <= n; i++)
        {
            if (a[j].a < a[i].a)
            {
                s2 = min(s2, a[i].b);
            }
        }
        if (s1 == 1e10 || s2 == 1e10)
        {
            continue;
        }
        ans = min(ans, s1 + s2 + a[j].b);
    }
    if (ans == 1e10)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
