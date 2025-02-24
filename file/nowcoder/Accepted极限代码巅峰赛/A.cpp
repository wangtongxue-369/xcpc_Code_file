#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    ans = 0;
    vector<bool> ve(n + 100, 0);
    ve[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (ve[i] == 1)
        {
            if (s[i] == '1')
            {
                ve[i + 1] = 0;
                ans++;
                continue;
            }
            else
            {
                ve[i + 1] = 1;
                continue;
            }
        }
        else
        {
            ve[i + 1] = 1;
        }
    }
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
