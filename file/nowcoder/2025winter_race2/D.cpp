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
    string s;
    cin >> s;
    map<ll, ll> ma;
    for (int i = 0; i < n; i++)
    {
        if (ma.contains(s[i]) == 0)
        {
            ma[s[i]]++;
            continue;
        }
        else
        {
            ans = n - i;
            break;
        }
    }
    ma.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        if (ma.contains(s[i]) == 0)
        {
            ma[s[i]]++;
            continue;
        }
        else
        {
            ans = max(ans, (ll)i + 1);
            break;
        }
    }
    cout << ans << '\n';
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
