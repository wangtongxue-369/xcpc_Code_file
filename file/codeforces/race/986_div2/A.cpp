#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    // cout << '!' << '\n';
    map<char, ll> x, y;
    x['N'] = 0;
    y['N'] = 1;
    x['E'] = 1;
    y['E'] = 0;
    x['S'] = 0;
    y['S'] = -1;
    x['W'] = -1;
    y['W'] = 0;
    ll a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    map<ll, pair<ll, ll>> pos;
    if (a == 0 && b == 0)
    {
        cout << "YES" << '\n';
        return;
    }
    ll x1 = 0, y1 = 0;
    set<pair<ll, ll>> se;
    for (int i = 0; i < n; i++)
    {
        x1 += x[s[i]];
        y1 += y[s[i]];
        pos[i] = {x1, y1};
        se.insert({x1, y1});
    }
    ll dx = 0, dy = 0;
    while (1)
    {
        if (se.count({a + dx, b + dy}))
        {
            cout << "YES\n";
            return;
        }
        dx -= x1, dy -= y1;
        if (dx == 0 && dy == 0)
        {
            cout << "NO\n";
            return;
        }
        if (abs(dx) > 20)
        {
            cout << "NO\n";
            return;
        }
        if (abs(dy) > 20)
        {
            cout << "NO\n";
            return;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     ll px = a - pos[i].first;
    //     ll py = b - pos[i].second;

    //     if (px % x1 == 0 && py % y1 == 0 && px / x1 == py / y1)
    //     {
    //         cout << "YES" << '\n';
    //         return;
    //     }
    // }
    // cout << "NO" << '\n';
    // return;
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
