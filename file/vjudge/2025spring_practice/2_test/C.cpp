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
    string s;
    cin >> s;
    cin >> n;
    string l, r;
    cin >> l >> r;
    vector<queue<ll>> ve(20);
    for (int i = 0; i < s.length(); i++)
    {
        // cout << s[i] - '0' << ' ' << i << '\n';
        ve[s[i] - '0'].push(i);
    }
    ll p = -1;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        ll x = p;
        // cout << p << '\n';
        // cout << x << '\n';
        for (int j = l[i] - '0'; j <= r[i] - '0'; j++)
        {
            // cout << p << '\n';
            while (ve[j].size() && ve[j].front() <= x)
            {
                ve[j].pop();
            }
            if (ve[j].size() == 0)
            {
                flag = 1;
                cout << "YES\n";
                return;
                // x = x + 10;
            }
            else
            {
                p = max(p, ve[j].front());
                // cout << p << '\n';
            }
        }
    }
    cout << "NO\n";
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
