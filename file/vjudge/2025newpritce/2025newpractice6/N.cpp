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
    ll op, t, h;
    vector<ll> ve(n + 10, 0);
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            ve[i] = ve[i - 1];
            q.emplace(i);
        }
        else if (op == 2)
        {
            cin >> t;
            ve[i] = ve[i - 1] + t;
        }
        else if (op == 3)
        {
            cin >> h;
            ve[i] = ve[i - 1];
            ans = 0;
            while (!q.empty() && ve[i] - ve[q.front()] >= h)
            {
                ans++;
                q.pop();
            }
            cout << ans << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
