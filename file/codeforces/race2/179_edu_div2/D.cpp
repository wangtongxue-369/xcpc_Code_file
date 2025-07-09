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
bool cmp(PII s1, PII s2)
{
    if (s1.first == s2.first)
    {
        return s1.second < s2.second;
    }
    return s1.first < s2.first;
}
void solve()
{
    cin >> n >> m;
    map<ll, vector<ll>> ma;
    vector<pair<ll, vector<ll>>> ve;
    vector<PII> v;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        v.push_back({a[i] / 100, a[i]});
        ma[a[i] / 100].push_back(a[i]);
    }
    sort(v.begin(), v.end());
    // for (auto it : v)
    // {
    //     cout << it.first << ' ' << it.second << '\n';
    // }
    for (auto it : ma)
    {
        ve.push_back(it);
    }

    ll n1 = n / 2, n2 = n / 2;
    vector<ll> v1, v2;
    for (int i = 0; i < n1; i++)
    {
        v1.push_back(v[i].second);
    }
    for (int i = v.size() - 1; i >= v.size() - n1; i--)
    {
        v2.push_back(v[i].second);
    }

    ll l = 0, r = m - 1;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << v[l].second << ' ' << v[r].second << ' ';
        }
        cout << '\n';
        for (int j = 1; j <= 3; j++)
        {
            cout << v[r].second << ' ' << v[l].second << ' ';
        }
        cout << '\n';
        l++, r--;
    }
    if (n % 2 == 1)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << v[l].second << ' ' << v[r].second << ' ';
        }
        cout << '\n';
    }
    // for (int i = 1; i <= n / 2; i++)
    // {
    //     for (int j = 1; j <= 3; j++)
    //     {
    //         cout << v1[i - 1] << ' ';
    //         cout << v2[i - 1] << ' ';
    //     }
    //     for (int j = 1; j <= 3; j++)
    //     {
    //         cout << v2[i - 1] << ' ';
    //         cout << v1[i - 1] << ' ';
    //     }
    //     cout << '\n';
    // }
    // if (n % 2 == 1)
    // {
    //     ll l = n / 2 + 1, r = n - (n / 2);
    //     for (int j = 1; j <= 3; j++)
    //     {
    //         cout << v[l - 1].second << ' ';
    //         cout << v[r].second << ' ';
    //     }
    //     cout << '\n';
    // }
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