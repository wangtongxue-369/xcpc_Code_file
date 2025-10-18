/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    ll sum0 = 0, sum1 = 0;
    for (auto it : s)
    {
        if (it == '0')
        {
            sum0++;
        }
        else
        {
            sum1++;
        }
    }
    vector<ll> a(n + 10), d(n + 10), c(n + 10);
    vector<PII> ve;
    for (int i = 1; i <= n; i++)
    {
        ll r = i;
        ll d = 1;
        while (r + 1 <= n && s[r + 1] == s[i])
        {
            r++;
            d++;
        }
        for (int j = i; j <= r; j++)
        {
            c[j] = d;
        }
        ve.push_back({r - i + 1, s[i] - '0'});
        i = r;
    }
    for (auto it : ve)
    {
        // cout << it.first << ' ' << it.second << '\n';
    }
    ll len = 1, sum = 0, size = 0;
    for (int i = 0; i < ve.size(); i++)
    {
        if (ve[i].second == 1)
        {
            continue;
        }
        ll l = i, r = i;
        sum = 0;
        size = 0;
        if (ve[i].second == 0)
        {
            sum += ve[i].first;
            size++;
            while (r + 1 < ve.size() && ((ve[r + 1].first == 1 && ve[r + 1].second == 1) || (ve[r + 1].second == 0)))
            {
                if (ve[r + 1].second == 0)
                {
                    size++;
                    sum += ve[r + 1].first;
                }
                r++;
            }
            ll en = r;
            if (ve[en].second == 1)
            {
                en--;
            }
            if (sum == size && sum % 2 == 1 && (l != 0 && en != ve.size() - 1))
            {
                cout << "NO\n";
                return;
            }
            i = r;
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