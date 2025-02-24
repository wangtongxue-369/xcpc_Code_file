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
void solve()
{
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    s[0] = 'x' + s[0] + 'x';
    s[1] = 'x' + s[1] + 'x';
    ll i = 0;
    for (int j = 1; j <= n; j++)
    {
        if (s[0][j] == '.')
        {
            ll sum0 = 0;
            if (s[0][j - 1] == 'x')
            {
                sum0++;
            }
            if (s[0][j + 1] == 'x')
            {
                sum0++;
            }
            if (s[1][j] == 'x')
            {
                sum0++;
            }
            ll sum1 = 3 - sum0;
            if (sum0 == 3)
            {
                ans++;
                continue;
            }
            if (sum0 == 2)
            {
                continue;
            }
            if (s[0][j - 1] == '.' && s[0][j + 1] == '.' && (s[1][j - 1] == 'x' || s[1][j] == 'x' || s[1][j + 1] == 'x'))
            {
                ans++;
                continue;
            }
            if (s[0][j - 1] == 'x' && s[0][j + 1] == '.' && s[1][j] == '.' && s[1][j + 1] == 'x')
            {
                ans++;
                continue;
            }
            if (s[0][j - 1] == '.' && s[0][j + 1] == 'x' && s[1][j] == '.' && s[1][j - 1] == 'x')
            {
                ans++;
                continue;
            }
        }
    }
    for (int j = 1; j <= n; j++)
    {
        if (s[1][j] == '.')
        {
            ll sum0 = 0;
            if (s[1][j - 1] == 'x')
            {
                sum0++;
            }
            if (s[1][j + 1] == 'x')
            {
                sum0++;
            }
            if (s[0][j] == 'x')
            {
                sum0++;
            }
            ll sum1 = 3 - sum0;
            if (sum0 == 3)
            {
                ans++;
                continue;
            }
            if (sum0 == 2)
            {
                continue;
            }
            if (s[1][j - 1] == '.' && s[1][j + 1] == '.' && (s[0][j - 1] == 'x' || s[0][j] == 'x' || s[0][j + 1] == 'x'))
            {
                ans++;
                continue;
            }
            if (s[1][j - 1] == 'x' && s[1][j + 1] == '.' && s[0][j] == '.' && s[0][j + 1] == 'x')
            {
                ans++;
                continue;
            }
            if (s[1][j - 1] == '.' && s[1][j + 1] == 'x' && s[0][j] == '.' && s[0][j - 1] == 'x')
            {
                ans++;
                continue;
            }
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
