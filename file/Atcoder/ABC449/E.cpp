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
bool cmp(PII s1, PII s2)
{
    if (s1.second == s2.second)
    {
        return s1.first < s2.first;
    }
    return s1.second < s2.second;
}
void solve()
{
    cin >> n >> m;
    ll x;
    vector<ll> cnt(m + 1);
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        x = a[i];
        cnt[x]++;
        maxn = max(maxn, cnt[x]);
    }
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += maxn - cnt[i];
    }
    vector<ll> an;
    for (int i = 1; i <= n; i++)
    {
        ll j = i;
        while (j + 1 <= n && cnt[j + 1] == cnt[i])
        {
            j++;
        }
        if (j + 1 > n)
        {
        }
        an.push_back(j);
        i = j;
    }

    ll qq;
    cin >> qq;
    while (qq--)
    {
        cin >> x;
        if (x <= n)
        {
            cout << a[x] << '\n';
            continue;
        }
        x -= n;
        if (x <= sum)
        {
            cout << an[x - 1] << '\n';
        }
        else
        {
            cout << (x - sum - 1) % m + 1 << '\n';
        }
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