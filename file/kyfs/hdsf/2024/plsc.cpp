/*
██╗  ██╗ █████╗ ███╗   ██╗███████╗███████╗██████╗
██║  ██║██╔══██╗████╗  ██║██╔════╝██╔════╝██╔══██╗
███████║███████║██╔██╗ ██║███████╗█████╗  ██████╔╝
██╔══██║██╔══██║██║╚██╗██║╚════██║██╔══╝  ██╔══██╗
██║  ██║██║  ██║██║ ╚████║███████║███████╗██║  ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝╚═╝  ╚═╝
*/
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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    stack<int> stk;
    for (int i = 1; i <= n; ++i)
    {
        while (!stk.empty() && a[stk.top()] <= a[i])
            stk.pop();
        if (!stk.empty())
            f[i] = stk.top();
        stk.push(i);
    }
    ll q, x, y;
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        if (x < y)
        {
            cout << "Yes\n";
            continue;
        }
        if (f[x] == 0)
        {
            cout << "No\n";
            continue;
        }
        if (f[x] >= y)
        {
            cout << "Yes\n";
            continue;
        }
        else
        {
            cout << "No\n";
            continue;
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