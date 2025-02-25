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
    vector<ll> ve;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    sort(ve.begin(), ve.end());
    ll len = unique(ve.begin(), ve.end()) - ve.begin();
    // cout << len << '\n';
    ll l = 0, r = 0;
    ans = 0;
    for (r = 0; r < len; r++)
    {
        // if (r==len-1)
        // {
        //     if (ve[])
        //     break;
        // }
        if ((ve[r + 1] - ve[l] + 1) <= n && r != len - 1)
        {
            continue;
        }
        else
        {
            ans = max(ans, r - l + 1);
            while ((ve[r + 1] - ve[l] + 1) > n && r != len - 1)
            {
                l++;
            }
        }
    }
    cout << ans << '\n';
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
