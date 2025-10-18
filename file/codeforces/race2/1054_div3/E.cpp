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
    ll k, l, r;
    cin >> n >> k >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 对于每一个右端点 看他最远和最近的合法区间
    map<ll, ll> ma;
    vector<ll> la(n + 10), ra(n + 10);
    ll j = 1;
    for (int i = 1; i <= n; i++)
    {
        ma[a[i]]++;
        while (ma.size() > k)
        {
            ma[a[j]]--;
            if (ma[a[j]] == 0)
            {
                ma.erase(a[j]);
            }
            j++;
        }
        if (ma.size() == k)
        {
            la[i] = j;
        }
        else
        {
            la[i] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << la[i] << ' ';
    }
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