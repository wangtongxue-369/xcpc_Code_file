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
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll sum = 0;

    vector<ll> ve;
    for (int i = n - 1; i >= 0; i--)
    {
        ve.push_back(sum);
        if (s[i] == '1')
        {
            sum++;
        }
        else
        {
            sum--;
        }
    }
    // ve.push_back(sum);
    sort(ve.begin(), ve.end(), cmp);
    sum = 0;
    for (m = 2; m <= n; m++)
    {
        sum += ve[m - 2];
        if (sum >= k)
        {
            cout << m << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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
