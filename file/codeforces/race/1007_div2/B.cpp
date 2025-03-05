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
    // n = 100 - _ + 1;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << '\n';
        return;
    }
    function<bool(ll x)> check = [&](ll x)
    {
        ll p = sqrtl(1.0 * x);
        return !(p * p == x);
    };
    priority_queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    ll sum = 0;
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        if (check(sum + q.top()))
        {
            sum += q.top();
            ve.push_back(q.top());
            q.pop();
        }
        else
        {
            // cout << i << '\n';
            if (q.size() == 1)
            {
                cout << -1 << '\n';
                return;
            }
            ll x = q.top();
            q.pop();
            ve.push_back(q.top());
            sum += q.top();
            q.pop();
            q.push(x);
        }
        // for (auto it : ve)
        // {
        //     cout << it << ' ';
        // }
        // cout << '\n';
    }
    for (auto it : ve)
    {
        cout << it << ' ';
    }
    cout << '\n';
}
// 1 4 9
// +1 3 5 7 9
// 2
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
