#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    ll x;
    cin >> n >> x;
    set<ll> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> ma;
    sort(a + 1, a + 1 + n);
    ll pos = 0;
    if (a[1] == 0)
    {
        pos++;
    }
    else
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            ma[a[i] % x]++;
            continue;
        }
        if (a[i] == pos)
        {
            pos++;
            continue;
        }
        else
        {
            if (ma[pos % x] >= 1)
            {
                ma[pos % x]--;
                pos++;
                i--;
                continue;
            }
            else
            {
                cout << pos << '\n';
                return;
            }
        }
    }
    while (ma[pos % x] >= 1)
    {
        ma[pos % x]--;
        pos++;
    }
    cout << pos << '\n';
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
