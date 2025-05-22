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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    cin >> m;
    ll x;
    multiset<int> wy, zy;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        wy.insert(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > a[i])
        {
            cout << "NO\n";
            return;
        }

        while (!zy.empty() && *zy.begin() < b[i])
        {
            zy.erase(zy.begin());
        }
        if (b[i] < a[i])
        {
            if (zy.contains(b[i]))
            {
                continue;
            }
            else
            {
                if (wy.contains(b[i]) == 1)
                {
                    wy.erase(wy.find(b[i]));
                    zy.insert(b[i]);
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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