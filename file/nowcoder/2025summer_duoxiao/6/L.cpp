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
PII v[MAXN];
bool cmp(PII s1, PII s2)
{
    if (s1.second == s2.second)
    {
        return s1.first < s2.first;
    }
    return s1.second < s2.second;
}
void solve()
{
    cin >> n >> m;
    vector<ll> a(2 * n + 10);
    set<ll> se;
    for (int i = 1; i <= 2 * n; i++)
    {
        se.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v + 1, v + 1 + m, cmp);
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        ll l = v[i].first;
        ll r = v[i].second;
        auto it = se.lower_bound(l);
        if (it == se.end() || *it > r)
        {
            cout << -1 << '\n';
            return;
        }
        sum++;
        a[*it] = 1;
        se.erase(it);
    }
    ll qkh = 0, kh = sum;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (a[i] == 1)
        {
            qkh++;
            continue;
        }
        else if (a[i] == 0)
        {
            if (kh < n && qkh + 1 <= 2 * n - i)
            {
                a[i] = 1;
                qkh++;
                kh++;
                continue;
            }
            else
            {
                if (qkh)
                {
                    a[i] = 2;
                    qkh--;
                    continue;
                }
                else
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    if (qkh >= 1 || kh != n)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (a[i] == 1)
        {
            cout << "(";
        }
        else
        {
            cout << ")";
        }
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