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
ll _ = 1, n, m, ans = 0, k = 0;
struct node
{
    ll s;
    ll c = 0;
    ll smin = 0, smax = 0;
    ll sum = 0;
    vector<ll> ve;
} a[MAXN];
void solve()
{
    ll x, smin = 0, smax = 0;
    cin >> n >> m >> k;
    map<ll, vector<array<ll, 3>>> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s;
        smin = 0, smax = 0;
        a[i].ve.clear();
        a[i].smax = 0, a[i].smin = 0, a[i].c = 0, a[i].sum = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            a[i].ve.push_back(x);
            if (x == -1)
            {
                smax += k;
                a[i].c++;
            }
            else
            {
                a[i].sum += x;
                smin += x;
                smax += x;
            }
        }
        ma[a[i].s].push_back({i, smin, smax});
        a[i].smin = smin;
        a[i].smax = smax;
    }
    map<ll, ll> d;
    // 每个i对应要有的sum
    ll l = 0;
    for (auto it : ma)
    {
        ll r = 1e18;
        if (it.second.size() == 1)
        {
            l = max(l, it.second[0][1]);
            r = min(r, it.second[0][2]);
            if (l <= r)
            {
                d[it.second[0][0]] = l;
            }
            else
            {
                cout << "No\n";
                return;
            }
            l++;
        }
        else
        {
            ll l1 = l, r = 1e18;
            ll pl = l;
            for (auto i : it.second)
            {
                if (max(i[1], l) <= i[2])
                {
                    d[i[0]] = max(i[1], l);
                    pl = max(pl, max(i[1], l));
                }
                else
                {
                    cout << "No\n";
                    return;
                }
            }
            l = pl;
            l++;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
    {
        ll p = d[i] - a[i].sum;
        for (int j = 0; j < m; j++)
        {
            if (a[i].ve[j] != -1)
            {
                cout << a[i].ve[j] << ' ';
            }
            else
            {
                cout << min(p, k) << ' ';
                p -= min(p, k);
            }
        }
        cout << '\n';
    }
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
