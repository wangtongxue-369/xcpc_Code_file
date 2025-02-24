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
ll _ = 1, n, m, ans = 0;
struct node
{
    ll p;
    ll v;
} a[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    vector<ll> le, ri;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].p >> a[i].v;
        if (a[i].v == -1)
        {
            le.push_back(a[i].p);
        }
        else
        {
            ri.push_back(a[i].p);
        }
    }
    sort(le.begin(), le.end());
    sort(ri.begin(), ri.end());
    bool flag = 0;
    double l = 0, r = 3e9;
    while ((r - l) > (1e-7))
    {
        ll s = 0;
        double mid = (l + r) / 2;
        for (auto p : ri)
        {
            auto it = upper_bound(le.begin(), le.end(), p + 2 * mid);
            ll p1 = it - le.begin() - 1;

            s += it - 1 - lower_bound(le.begin(), le.end(), p) + 1;
        }
        if (s >= k)
        {
            flag = 1;
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (flag == 0)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        printf("%6lf", l);
        // cout << l << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
