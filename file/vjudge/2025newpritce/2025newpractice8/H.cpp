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
    string s[10];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    vector<ll> a;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }
    while (next_permutation(a.begin(), a.end()))
    {
        bool flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            ll sum = 0;
            for (int j = 0; j < m; j++)
            {
                if (s[a[i]][j] != s[a[i + 1]][j])
                {
                    sum++;
                }
            }
            if (sum != 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
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
