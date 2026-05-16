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
#define ld long double
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], lon[MAXN];
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<ll> lon(200);
    lon[1] = s1.length();
    lon[2] = s2.length();
    ll len = 2;
    while (1)
    {
        len++;
        lon[len] = min((ll)1e18, lon[len - 1] + lon[len - 2]);
        if (lon[len] >= 1e18)
        {
            break;
        }
    }
    vector<array<ll, 26>> a(len + 10);
    vector<array<ll, 26>> pres1(s1.length() + 1);
    vector<array<ll, 26>> pres2(s2.length() + 1);
    for (int i = 1; i <= s1.length(); i++)
    {
        pres1[i] = pres1[i - 1];
        pres1[i][s1[i - 1] - 'a']++;
    }
    for (int i = 1; i <= s2.length(); i++)
    {
        pres2[i] = pres2[i - 1];
        pres2[i][s2[i - 1] - 'a']++;
    }
    for (int c = 0; c < 26; c++)
    {
        a[1][c] = pres1[s1.length()][c];
        a[2][c] = pres2[s2.length()][c];
    }
    for (int i = 3; i <= len; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            a[i][c] = min((ll)1e18, a[i - 1][c] + a[i - 2][c]);
        }
    }
    function<ll(ll, ll, char)> dfs = [&](ll x, ll p, char c) -> ll
    {
        if (p == 0)
            return 0;

        if (x == 1)
        {
            if (p >= s1.size())
            {
                return a[1][c - 'a'];
            }
            else
            {
                return pres1[p][c - 'a'];
            }
        }

        if (x == 2)
        {
            if (p >= s2.size())
            {
                return a[2][c - 'a'];
            }
            else
            {
                return pres2[p][c - 'a'];
            }
        }

        if (p <= lon[x - 1])
        {
            return dfs(x - 1, p, c);
        }
        else
        {
            ll l = a[x - 1][c - 'a'];
            ll r = dfs(x - 2, p - lon[x - 1], c);
            return l + r;
        }
    };

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        char c;
        cin >> l >> r >> c;
        cout << dfs(len, r, c) - dfs(len, l - 1, c) << '\n';
    }
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