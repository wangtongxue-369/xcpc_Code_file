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
    ll r = 0;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 0;
    ll tmp = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = n; i >= 1; i--)
    {
        if (r + k <= n - i)
        {
            tmp += a[i];
            r += k + 1;
            q.push(a[i]);
        }
        else
        {
            if (q.size() && q.top() < a[i])
            {
                tmp -= q.top();
                tmp += a[i];
                q.pop();
                q.push(a[i]);
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
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