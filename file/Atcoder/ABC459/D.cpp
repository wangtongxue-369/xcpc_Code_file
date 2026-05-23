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
    string s;
    cin >> s;
    vector<PII> ve(26);
    ll p = 0;
    for (auto &it : ve)
    {
        it.second = p;
        p++;
    }
    for (auto it : s)
    {
        ve[it - 'a'].first++;
    }
    sort(ve.begin(), ve.end(), greater<PII>());
    n = s.length();
    if ((n + 1) / 2 < ve[0].first)
    {
        cout << "No\n";
        return;
    }
    reverse(ve.begin(), ve.end());
    cout << "Yes\n";
    string ans(n, ' ');
    for (int p = 0; p <= 1; p++)
    {
        for (int i = p; i < n; i += 2)
        {
            ans[i] = (char)(ve.back().second + 'a');
            ve.back().first--;
            if (ve.back().first == 0)
            {
                ve.pop_back();
            }
        }
    }
    cout << ans;
    cout << '\n';
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