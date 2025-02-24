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
    string s;
    cin >> n >> s;
    stack<ll> ans;
    vector<ll> a(n + 10, 0);
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] * (ll)(i + 1);
    }
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    res = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ans.push(res % 10);
        res /= 10;
        res += a[i];
    }
    while (res)
    {
        ans.push(res % 10);
        res /= 10;
    }
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << '\n';
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
// 5 7 9
// 个位 5 7 9 57 79 579   5 7 9 7 9 9
// 十位 57 79 579         5 7 7
// 百位 579               5
// 个位所有数都有贡献，第i位贡献i次，
//
