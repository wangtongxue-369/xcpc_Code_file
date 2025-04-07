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
ll x, y;
bool flag = 0;
void dfs(ll c, ll s1, ll s2)
{
    if (c == 3)
    {
        if (s1 == x && s2 == y)
        {
            flag = 1;
            return;
        }
        else
        {
            return;
        }
    }
    dfs(c + 1, s1 + 1, s2);
    dfs(c + 1, s1, s2 + 2);
    dfs(c + 1, s1, s2 + 3);
    dfs(c + 1, s1 + 4, s2);
    dfs(c + 1, s1, s2 + 5);
    dfs(c + 1, s1, s2 + 6);
}
void solve()
{
    cin >> x >> y;
    dfs(0, 0, 0);
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
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
