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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<array<vector<ll>, 2>> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        ll p = i;
        for (ll j = 0; j <= 670; j++)
        {
            p = i + j;
            sum += ((j + 1) * (j + 1)) * a[p];
            if (sum == a[p + 1])
            {
                ve[p + 1][0].push_back(i);
            }
        }
        sum = 0;
        p = i + 1;
        for (ll j = 1; j <= 670; j++)
        {
            p = i + j;
            sum += (j * j) * a[p];
            if (sum == a[i])
            {
                ve[i][1].push_back(p);
                break;
            }
            if (sum > a[i])
            {
                break;
            }
        }
    }
    vector<ll> f(n + 10);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (auto it : ve[i][0])
            if (f[it - 1])
                f[i] = 1;

        for (int it : ve[i][1])
            if (f[i - 1])
                f[it] = 1;
    }
    if (f[n])
        cout << "YES\n";
    else
        cout << "NO\n";
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