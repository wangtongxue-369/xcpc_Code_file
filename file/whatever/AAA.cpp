/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
    vector<string> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> ve[i];
        ve[i] = ' ' + ve[i];
    }
    vector<ll> cu(n + 10, 0);
    set<ll> se;
    for (int i = 1; i <= n; i++)
        se.insert(i);
    for (auto it1 : se)
    {
        for (auto it2 : se)
        {
            if (ve[it1][it2] == '1')
            {
                cu[it1]++;
            }
        }
    }
    ll A = -1, B = -1, C = -1;
    for (auto it : se)
        if (A == -1 || cu[A] < cu[it])
            A = it;
    // cout << A << '\n';
    se.clear();
    for (int i = 1; i <= n; i++)
    {
        if (ve[i][A] == '1')
        {
            se.insert(i);
        }
    }
    if (se.size() == 0)
    {
        cout << "NOT FOUND\n";
        return;
    }
    // B
    for (int i = 1; i <= n; i++)
        cu[i] = 0;
    B = -1;
    for (auto it1 : se)
    {
        for (auto it2 : se)
        {
            if (ve[it1][it2] == '1')
            {
                cu[it1]++;
            }
        }
    }
    for (auto it : se)
        if (B == -1 || cu[B] < cu[it])
            B = it;
    // cout << B << '\n';
    set<ll> se1;
    for (int it = 1; it <= n; it++)
    {
        cu[it] = 0;
        if (ve[it][B] == '1')
        {
            se1.insert(it);
        }
    }
    if (se1.size() == 0)
    {
        cout << "NOT FOUND\n";
        return;
    }
    se = se1;
    se1.clear();
    // C
    for (int i = 1; i <= n; i++)
        cu[i] = 0;
    C = -1;
    for (auto it1 : se)
    {
        for (auto it2 : se)
        {
            if (ve[it1][it2] == '1')
            {
                cu[it1]++;
            }
        }
    }
    for (auto it : se)
        if (C == -1 || cu[C] < cu[it])
            C = it;
    // cout << C << '\n';
    for (int it = 1; it <= n; it++)
    {
        cu[it] = 0;
        if (ve[it][C] == '1')
        {
            se1.insert(it);
        }
    }
    if (se1.size() == 0)
    {
        cout << "NOT FOUND\n";
        return;
    }
    cout << A << ' ' << B << ' ' << C << '\n';
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