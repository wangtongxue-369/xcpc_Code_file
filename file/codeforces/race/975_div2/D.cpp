#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll suml = 0, sumr = 0;
    map<ll, vector<ll>> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]].push_back(i);
    }
    ll ansl = 1, ansr = n;
    ll l = n, r = 1;
    for (int i = 1; i <= n; i++)
    {

        if (ma[i].size() == 0)
        {
            continue;
        }
        for (auto it : ma[i])
        {
            r = max(r, it);
            l = min(l, it);
        }
        if (r - l + 1 > i)
        {
            cout << 0 << '\n';
            return;
        }
        ansl = max(ansl, r - i + 1);
        ansr = min(ansr, l + i - 1);
        if (ansl > ansr)
        {
            cout << 0 << '\n';
            return;
        }
    }
    cout << ansr - ansl + 1 << '\n';
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
