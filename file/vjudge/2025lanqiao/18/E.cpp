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
    ll x;
    cin >> n >> m;
    string s = "NO";
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x]++;
        if (a[x] >= 2)
        {
            s = "YES";
        }
    }
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cout << s << '\n';
            continue;
        }
        bool flag = 0;
        for (ll i = 1; i * x <= 200000; i++)
        {
            if (a[i] >= 1 && a[x * i] >= 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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
