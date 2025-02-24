#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i]]++;
    }
    for (int i = 'a'; i < 'z'; i++)
    {
        ans += a[i] * a[i + 1];
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
