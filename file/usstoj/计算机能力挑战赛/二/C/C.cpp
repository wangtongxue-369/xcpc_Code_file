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
    while (cin >> s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                s[i] -= ('a' - 'A');
            }
            a[s[i]]++;
        }
    }
    ll maxn = 0, minn = 1e9;
    for (int i = 'A'; i <= 'Z'; i++)
    {

        if (a[i] == 0)
        {
            continue;
        }
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    ll s1 = maxn - minn;
    if (s1 == 1 || s1 == 0)
    {
        cout << "No Answer" << '\n';
        cout << 0 << '\n';
        return;
    }
    for (int i = 2; i <= sqrt(s1); i++)
    {
        if (s1 % i == 0)
        {
            cout << "No Answer" << '\n';
            cout << 0 << '\n';
        }
    }
    cout << "Lucky Word" << '\n';
    // cout << (char)('a' - ('a' - 'A')) << '\n';
    cout << s1 << '\n';
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
