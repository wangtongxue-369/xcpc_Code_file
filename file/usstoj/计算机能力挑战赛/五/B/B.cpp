#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 1, a[N], f[N];
void solve()
{
    string s;
    cin >> s;
    for (ll i = 1; i <= s.length(); i++)
    {
        if (s.length() % i == 0)
        {
            bool flag = 0;
            for (int j = 0; j < s.length(); j += i)
            {
                if (s.substr(0, i) != s.substr(j, i))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                continue;
            }
            else
            {
                ans = max(ans, (ll)(s.length() / i));
            }
        }
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
