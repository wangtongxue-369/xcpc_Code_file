#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];
void solve()
{
    string s;
    cin >> s;
    n = s.length();
    // s = ' ' + s;
    ll sum = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        ll s1 = 0, s2 = 0;
        for (int j = 0; j <= i; j++)
        {
            s1 = s1 * 10 + s[j] - '0';
        }
        for (int j = i + 1; j < s.length(); j++)
        {
            s2 = s2 * 10 + s[j] - '0';
        }
        ans = max(ans, s1 + s2);
    }
    cout << ans << '\n';
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
