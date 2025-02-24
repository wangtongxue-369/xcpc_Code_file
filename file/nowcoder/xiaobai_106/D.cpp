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
ll _ = 1, n, m, k, a, b, x, y;
void solve()
{
    cin >> n >> k >> a >> b >> x >> y;
    vector<int> aa(n + 10, -1);
    queue<int> q;
    q.push(a);
    aa[a] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (aa[(p + x) % n] == -1)
        {
            aa[(p + x) % n] = aa[p] + 1;
            q.push((p + x) % n);
        }
        if (aa[(p - y + n) % n] == -1)
        {
            aa[(p - y + n) % n] = aa[p] + 1;
            q.push((p - y + n) % n);
        }
        if (k && aa[(p + n / 2) % n] == -1)
        {
            aa[(p + n / 2) % n] = aa[p] + 1;
            q.push((p + n / 2) % n);
        }
    }
    cout << aa[b] << '\n';
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
