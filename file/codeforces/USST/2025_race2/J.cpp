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
ll _ = 1, n, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    string op;
    char c;
    ll m;
} a[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    queue<PII> ve;
    ve.push({1, n});
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].op;
        if (a[i].op == "echo")
        {
            cin >> a[i].c;
        }
        else
        {
            cin >> a[i].m;
        }
    }
    string s;
    ll p = 0;
    while (ve.size() && p <= k)
    {
        auto [l, r] = ve.front();
        ve.pop();
        for (int i = l; i <= r && p < k; i++)
        {
            p++;
            if (a[i].op == "echo")
            {
                s += a[i].c;
            }
            else
            {
                ve.push({1, a[i].m});
            }
        }
    }
    cout << s << '\n';
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
