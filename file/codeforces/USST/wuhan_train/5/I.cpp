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
    string s;
    cin >> s;
    ll p = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            p = i;
            break;
        }
    }
    if (p == -1)
    {
        cout << 0 << '\n';
        return;
    }
    ans = 0;
    for (int i = p; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            ans++;
            while (i + 1 < s.length() && s[i + 1] == '0')
            {
                i++;
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}