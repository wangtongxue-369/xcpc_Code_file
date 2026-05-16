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
struct node
{
    ll h, x;
};
bool cmp(node s1, node s2)
{
    return s1.x < s2.x;
}
void solve()
{
    cin >> n >> m;
    vector<node> ve(n);
    for (auto &[x, y] : ve)
    {
        cin >> x;
    }
    for (auto &[x, y] : ve)
    {
        cin >> y;
    }
    sort(ve.begin(), ve.end(), cmp);
    vector<ll> v;
    for (int i = 0; i < ve.size(); i++)
    {
        int j = i + 1;
        ll p = ve[i].h + ve[i].x;
        while (j < ve.size() && ve[j].x <= p)
        {
            p = max(ve[j].x + ve[j].h, p);
            j++;
        }
        j--;
        v.push_back(j - i + 1);
        i = j;
    }
    ans = 0;
    sort(v.begin(), v.end(), greater<ll>());
    for (int i = 0; i < min((ll)v.size(), m); i++)
    {
        ans += v[i];
    }
    cout << ans << '\n';
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