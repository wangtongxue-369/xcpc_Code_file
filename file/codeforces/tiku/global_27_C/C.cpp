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
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll lowbit = n & (~n);
    ll p = 1;
    while (p * 2 <= n)
    {
        p *= 2;
    }
    if (n % 2 == 1)
    {
        vector<ll> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 3 || i == n - 1 || i == n)
            {
                continue;
            }
            ans.push_back(i);
        }
        ans.push_back(1);
        ans.push_back(3);
        ans.push_back(n - 1);
        ans.push_back(n);
        cout << n << '\n';
        for (auto it : ans)
        {
            cout << it << ' ';
        }
        cout << '\n';
        return;
    }
    if (p != n)
    {
        cout << p * 2 - 1 << '\n';
        vector<ll> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i == n || i == n - 1 || i == p - 1)
            {
                continue;
            }
            ans.push_back(i);
        }
        ans.push_back(n);
        ans.push_back(n - 1);
        ans.push_back(p - 1);
        for (auto it : ans)
        {
            cout << it << ' ';
        }
        cout << '\n';
    }
    else
    {
        vector<ll> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 3 || i == n - 2 || i == n - 1 || i == n)
            {
                continue;
            }
            ans.push_back(i);
        }
        ans.push_back(1);
        ans.push_back(3);
        ans.push_back(n - 2);
        ans.push_back(n - 1);
        ans.push_back(n);
        cout << p * 2 - 1 << '\n';
        for (auto it : ans)
        {
            cout << it << ' ';
        }
        cout << '\n';
    }
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
