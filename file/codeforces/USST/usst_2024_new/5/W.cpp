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
    ll k, w;
    cin >> n >> m >> k >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    b[0] = 0, b[m + 1] = w + 1;
    a[n + 1] = 2e18;
    ans = 0;
    ll tp = 1;
    ll up = 0;
    vector<ll> an;
    for (int i = 1; i <= m + 1; i++)
    {
        vector<ll> re;
        ll start = b[i - 1], end = b[i];
        if (start + 1 == end || a[tp] >= end)
        {
            continue;
        }
        while (a[tp] < end)
        {
            if (re.empty())
            {
                re.push_back(a[tp]);
                up = a[tp];
            }
            else
            {
                if (a[tp] > up + k - 1)
                {
                    re.push_back(a[tp]);
                    up = a[tp];
                }
            }
            tp++;
        }
        ll res = re.size();
        if (re[res - 1] + k - 1 >= end)
        {
            re[res - 1] -= re[res - 1] + k - 1 - end + 1;
            for (int j = res - 2; j >= 0; j--)
            {
                if (re[j] + k - 1 >= re[j + 1])
                {
                    re[j] -= re[j] + k - 1 - re[j + 1] + 1;
                }
            }
            if (re[0] <= start)
            {
                cout << -1 << '\n';
                return;
            }
            ans += res;
            for (int p = 0; p < res; p++)
            {
                an.push_back(re[p]);
            }
        }
        else
        {
            ans += res;
            for (int p = 0; p < res; p++)
            {
                an.push_back(re[p]);
            }
        }
    }
    cout << ans << '\n';
    for (auto it : an)
    {
        cout << it << ' ';
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
