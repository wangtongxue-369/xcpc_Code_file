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
    cin >> n >> m;
    vector<string> s;
    string ss;

    for (int i = 1; i <= n; i++)
    {
        cin >> ss;
        s.push_back(ss);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '1')
            {
                ll p = 2;
                for (int w = 0; w <= j; w++)
                {
                    if (s[i][w] == '0')
                    {
                        p--;
                        break;
                    }
                }
                for (int w = 0; w <= i; w++)
                {
                    if (s[w][j] == '0')
                    {
                        p--;
                        break;
                    }
                }
                if ((p == 0))
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    return;
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