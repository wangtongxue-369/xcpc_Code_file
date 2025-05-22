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
    cin >> n;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    ll p = 0;
    ll su = 1;
    deque<ll> q;
    bool flag = 0;
    ll la = -10;
    for (auto it : ma)
    {
        if (it.first != la + 1)
        {
            la = it.first;
            flag = 0;
        }
        else
        {
            la = it.first;
        }
        if (it.second >= 4)
        {
            cout << "YES\n";
            return;
        }
        if (flag && it.second >= 2)
        {
            cout << "YES\n";
            return;
        }
        if (!flag && it.second >= 2)
        {
            flag = 1;
        }
    }
    cout << "NO\n";
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