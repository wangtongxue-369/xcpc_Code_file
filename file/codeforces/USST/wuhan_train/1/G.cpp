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
    if (n == 1)
    {
        cout << "impossible\n";
        return;
    }
    if (n == 2)
    {
        cout << "1 0\n";
        return;
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 2; i < n; i++)
    {
        q.push(i);
    }
    vector<ll> ve;
    ll p = 1;
    ve.push_back(1);
    ve.push_back(0);
    while (!q.empty())
    {
        // cout << q.top() << '\n';
        // cout << p << ' ' << q.top() << '\n';
        if ((p ^ q.top()) != 0)
        {
            p ^= q.top();
            ve.push_back(q.top());
            q.pop();
        }
        else
        {
            // cout << "!!!\n";
            ll x = q.top();
            q.pop();
            if (q.empty())
            {
                cout << "impossible\n";
                return;
            }
            else
            {
                p ^= q.top();
                ve.push_back(q.top());
                q.pop();
                q.push(x);
            }
        }
    }
    // cout << '\n';
    for (auto it : ve)
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
