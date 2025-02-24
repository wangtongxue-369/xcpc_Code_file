#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], b[N];
void solve()
{
    ll p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    ll i = 1;
    map<ll, ll> ma;
    bool flag = 0;
    for (int j = 1; j <= m; j++)
    {
        if (ma[b[j]] >= 1)
        {
            continue;
        }
        else
        {
            if (a[i] == b[j])
            {
                ma[a[i]]++;
                i++;
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "TIDAK" << '\n';
    }
    else
    {
        cout << "YA" << '\n';
    }
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
