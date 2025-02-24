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
    vector<ll> np(n + 10, n + 1);
    vector<ll> ls(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 's')
        {
            ls[i] = i;
        }
        else
        {
            ls[i] = ls[i - 1];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == 'p')
        {
            np[i] = i;
        }
        else
        {
            np[i] = np[i + 1];
        }
    }
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        ll p = np[i], s = n - ls[i] + 1;
        if (1 <= p && p <= n && 1 <= s && s <= n)
        {
            ve.push_back(min(p, s));
            continue;
        }
        if (p != n + 1)
        {
            ve.push_back(p);
            continue;
        }
        else if (s != n + 1)
        {
            ve.push_back(s);
            continue;
        }
        else
        {
            ve.push_back(n);
        }
    }
    sort(ve.begin(), ve.end());
    // for (auot it:ve)
    // {
    //        if (s[i]=='p')
    {
        }
    // }
    for (int i = 0; i < n; i++)
    {
        if (ve[i] < i + 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
