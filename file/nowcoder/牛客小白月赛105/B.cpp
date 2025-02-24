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
    string s1, s2;
    cin >> s1 >> s2;
    ll p1 = s1.length(), p2 = s2.length();
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '.')
        {
            p1 = i;
        }
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == '.')
        {
            p2 = i;
        }
    }
    if (p1 != p2)
    {
        cout << "NO\n";
        return;
    }
    // cout << p1 << p2;
    for (int i = 0; i < p1; i++)
    {
        if (s1[i] == s2[i])
        {
            continue;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = p1 + 1; i <= p1 + 6; i++)
    {
        char c1, c2;
        if (i >= s1.length())
        {
            c1 = '0';
        }
        else
        {
            c1 = s1[i];
        }
        if (i >= s2.length())
        {
            c2 = '0';
        }
        else
        {
            c2 = s2[i];
        }
        if (c1 == c2)
        {
            continue;
        }
        else
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
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
