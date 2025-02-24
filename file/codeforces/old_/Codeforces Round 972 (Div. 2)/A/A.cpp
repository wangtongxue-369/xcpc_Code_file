#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld 0x3f
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m; // ans = 0, a[500005], f[500005];
void solve()
{
    cin >> n;
    string s = "aeiou";
    string ans;
    for (int i = 0; i < n; i++)
    {
        ans += s[i % 5];
    }
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
