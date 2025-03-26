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
    bool flag = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            continue;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << s.length() / 2 << '\n';
        return;
    }
    vector<ll> ve;
    ll p = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            p++;
        }
        else
        {
            ve.push_back(p);
            p = 1;
        }
    }
    if (s[0] == s[s.length() - 1])
    {
        ve[0] += p;
    }
    else
    {
        ve.push_back(p);
    }
    ll sum = 0;
    flag = 0;
    for (auto it : ve)
    {
        // cout << it << ' ';
        if (it % 2 == 0)
        {
            flag = 1;
        }
        sum += it / 2;
    }
    // cout << '\n';
    cout << sum - (ll)flag << '\n';
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
