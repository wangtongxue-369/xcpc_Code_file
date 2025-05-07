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
    string s;
    cin >> s;
    s = ' ' + s;
    ll cnt01 = 0, cnt10 = 0;
    if (s[1] == '1')
    {
        cnt01++;
    }
    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] == '0' && s[i] == '1')
        {
            cnt01++;
        }
        if (s[i - 1] == '1' && s[i] == '0')
        {
            cnt10++;
        }
    }
    ll sum = n + cnt10 + cnt01;

    // for (int i = 2; i <= n; i++)
    // {
    //     if (s[i - 1] == s[i])
    //     {
    //         continue;
    //     }
    //     if (s[i - 1] != s[i])
    //     {
    //     }
    // }
    if (cnt01 >= 2 || cnt10 >= 2)
    {
        cout << sum - 2 << '\n';
        return;
    }
    if (cnt01 && cnt10)
    {
        cout << sum - 1 << '\n';
        return;
    }
    cout << sum << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}