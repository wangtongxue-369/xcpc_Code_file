#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    ans = 0;
    for (int i = 0; i < min(s1.length(), s2.length()); i++)
    {
        if (s1[i] == s2[i])
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    if (ans > 0)
    {
        cout << ans + 1 + s1.length() - ans + s2.length() - ans << '\n';
    }
    else
    {
        cout << s1.length() + s2.length() << '\n';
    }
    // cout<<ans+1+(max(s1.length(),s2.length())-ans)
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
