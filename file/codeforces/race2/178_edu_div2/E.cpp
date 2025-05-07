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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<vector<ll>> np(n + 10, vector<ll>(k + 10, n + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        np[i] = np[i + 1];
        np[i][s[i + 1] - 'a'] = i + 1;
    }
    vector<ll> f(n + 2, 0);
    for (int i = n; i >= 0; i--)
    {
        ll mn = INF;
        for (int j = 0; j < k; j++)
        {
            mn = min(mn, f[np[i][j]]);
        }
        f[i] = 1 + mn;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        string t;
        cin >> t;
        ll p = 0;
        bool flag = 1;
        for (auto it : t)
        {
            p = np[p][it - 'a'];
            if (p == n + 1)
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << f[p] << '\n';
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