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
ll _ = 1, n, m, ans = 0; // a[MAXN], b[MAXN];
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    vector<ll> a, b;
    cin >> n >> m;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (a.empty())
        {
            a.push_back(x);
            continue;
        }
        else if (x > a[0])
        {
            a.push_back(x);
            continue;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    // vector<ll> d;
    // for (int i = 1; i <= n; i++)
    // {
    //     auto it = upper_bound(b.begin(), b.end(), a[i]);
    //     if (it == b.end())
    //     {
    //         d.push_back(m);
    //     }
    //     else{
    //         d.push_back(it-b.begin()-1);
    //     }
    // }
    ll j = 0;
    vector<ll> c;
    for (int i = 0; i < m; i++)
    {
        while (j < a.size() && a[j] < b[i])
        {
            j++;
        }
        if (j > 0 && j < a.size())
        {
            c.push_back(a.size() - j);
        }
    }
    sort(c.begin(), c.end(), cmp);
    for (ll k = 1; k <= m; k++)
    {
        ll sc = m % k;
        ll t = m / k;
        for (int j = sc; j < c.size(); j += k)
        {
            t += c[j];
        }
        cout << t << ' ';
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
