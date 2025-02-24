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
ll _ = 1, n, m, ans = 0, d;
void solve()
{
    vector<ll> a(110, 0);
    string s[110];
    cin >> n >> d;
    for (int i = 1; i <= d; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i] += s[i][j] - '0';
        }
    }
    vector<ll> f(110, 0);
    ans = 0;
    for (int i = 1; i <= d; i++)
    {
        if (a[i] < n)
        {
            f[i] = f[i - 1] + 1;
        }
        else
        {
            f[i] = 0;
        }
        ans = max(ans, f[i]);
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
