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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    map<ll, ll> hen, shu;
    ll n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    ll x1, x2, y1, y2;
    for (int i = 1; i <= d; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            hen[min(y1, y2)]++;
        }
        else
        {
            shu[min(x1, x2)]++;
        }
    }
    vector<PII> h, s;
    for (auto it : hen)
    {
        h.push_back({it.second, -1 * it.first});
    }
    for (auto it : shu)
    {
        s.push_back({it.second, -1 * it.first});
    }

    function<bool(PII s1, PII s2)> cmp = [&](PII s1, PII s2)
    {
        return s1.second > s2.second;
    };
    sort(h.begin(), h.end(), greater<PII>());
    sort(s.begin(), s.end(), greater<PII>());
    sort(h.begin(), h.begin() + l, cmp);
    sort(s.begin(), s.begin() + k, cmp);

    for (int i = 0; i < min((ll)s.size(), k); i++)
    {
        cout << -1 * s[i].second << ' ';
    }
    cout << '\n';
    for (int i = 0; i < min((ll)h.size(), l); i++)
    {
        cout << -1 * h[i].second << ' ';
    }
    cout << '\n';
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