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
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + 2 * n, cmp);
    vector<ll> ve;
    ve.push_back(a[1]);
    ll r = 2 * n;
    ll sum = 0;
    for (int i = 2; i < r; i++)
    {
        sum += a[r];
        sum -= a[i];
        ve.push_back(a[r]);
        ve.push_back(a[i]);
        r--;
    }
    sum = sum - a[n + 1];
    ll p = a[1] - sum;
    ve.push_back(p);
    ve.push_back(a[n + 1]);
    for (auto it : ve)
    {
        cout << it << ' ';
    }
    cout << '\n';
    return;

    sort(a + 1, a + 1 + 2 * n);
    ll sumj = 0, sumo = 0;
    map<ll, ll> ma;
    for (int i = 1; i <= 2 * n; i++)
    {
        // cout << a[i] << ' ';
        ma[a[i]]++;
        if (i <= n)
        {
            sumj += a[i];
        }
        else
        {
            sumo += a[i];
        }
    }
    ll a1 = sumo - sumj;
    // cout << a1 << '\n';
    if (ma.contains(a1) == 0 && a1 > 0)
    {
        cout << a1 << ' ';
        for (int i = 1; i <= n; i++)
        {
            cout << a[i + n] << ' ' << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    sort(a + 1, a + 1 + 2 * n, cmp);
    sumj = 0;
    sumo = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % 2 == 1)
        {
            sumj += a[i];
        }
        else
        {
            sumo += a[i];
        }
    }
    cout << sumj - sumo << ' ';
    for (int i = 1; i <= n; i++)
    {
        cout << a[2 * i - 1] << ' ' << a[2 * i] << ' ';
    }
    cout << '\n';

    // swap(a[1], a[2 * n]);
    // sort(a + 2, a + 1 + 2 * n);
    // ll sum = 0;
    // for (int i = 2; i <= 2 * n; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         sum -= a[i];
    //     }
    //     else
    //     {
    //         sum += a[i];
    //     }
    // }
    // cout << a[1] << ' ' << sum << ' ' << a[n + 1] << ' ';
    // for (int i = 2; i <= n; i++)
    // {
    //     cout << a[i] << ' ' << a[i + n] << ' ';
    // }
    // cout << '\n';
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
