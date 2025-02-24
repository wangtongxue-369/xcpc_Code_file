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
    ll k;
    cin >> k;
    ll nm = k - 2;
    map<ll, ll> ma;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    for (int i = 1; i * i <= nm; i++)
    {
        if (nm % i != 0)
        {
            continue;
        }
        ll j = nm / i;
        if (i == j)
        {
            if (ma.count(i) != 0 && ma[i] >= 2)
            {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
        if (ma.count(i) != 0 && ma.count(j) != 0)
        {
            cout << i << ' ' << j << '\n';
            return;
        }
    }
    return;
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
