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
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    cin >> n >> m;
    // deque<ll> de;
    ll maxn = 0;
    queue<ll> q1, q2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q1.push(a[i]);
        // maxn = max(maxn, a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        // q2.push(b[i]);
    }
    sort(b + 1, b + 1 + m, greater<ll>());
    for (int i = 1; i <= m; i++)
    {
        q2.push(b[i]);
    }
    while (q1.size() && q2.size())
    {
        if (q1.front() >= q2.front())
        {
            cout << q1.front() << ' ';
            q1.pop();
            continue;
        }
        else
        {
            cout << q2.front() << ' ';
            q2.pop();
            continue;
        }
    }
    while (q1.size())
    {
        cout << q1.front() << ' ';
        q1.pop();
    }
    while (q2.size())
    {
        cout << q2.front() << ' ';
        q2.pop();
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
