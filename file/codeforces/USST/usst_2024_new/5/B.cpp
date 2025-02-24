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
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    cin >> n;
    ll sum = 0;
    vector<ll> z, f;
    ll sum0 = 0;
    ll sumz = 0, sumf = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] < 0)
        {
            sumf += a[i];
            f.push_back(a[i]);
        }
        else
        {
            sumz += a[i];
            z.push_back(a[i]);
        }
    }
    if (sumz + sumf == 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (sumz + sumf > 0)
    {
        sort(a + 1, a + 1 + n, cmp);
    }
    else
    {
        sort(a + 1, a + 1 + n);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
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
