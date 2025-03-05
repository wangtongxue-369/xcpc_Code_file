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
    string s;
    cin >> s;
    vector<ll> a(n + 10);
    vector<ll> cnt(4 * n + 10);
    a[0] = 3 * n;
    for (int i = 0; i < n; i++)
    {
        a[i + 1] = a[i] + (s[i] == '0' ? 1 : -3);
    }
    ll ans = 0, sum = 0;
    for (int i = 0, j = 3 * n; i <= n; i++)
    {
        if (a[i] + 1 <= 4 * n)
        {
            ans += cnt[a[i] + 1];
        }
        ll r = max(-1ll, a[i] - 2);
        while (j < r)
        {
            sum += cnt[++j];
        }
        while (j > r)
        {
            sum -= cnt[j--];
        }
        ans += sum;
        cnt[a[i]]++;
        if (a[i] <= j)
        {
            sum++;
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
