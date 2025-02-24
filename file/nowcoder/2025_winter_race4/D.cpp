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
    string s1, s2;
    cin >> s1 >> s2;
    map<char, ll> ma, ma2;
    if (m > n)
    {
        swap(s1, s2);
        swap(n, m);
    }
    for (auto it : s1)
    {
        ma[it]++;
    }
    ll sum = 0;
    for (auto it : s2)
    {
        if (ma[it] > 0)
        {
            ma[it]--;
        }
        else
        {
            sum++;
        }
    }
    ans = 0;
    for (auto [x, y] : ma)
    {
        if (y % 2 == 1)
        {
            ans++;
        }
    }
    if (sum > ans)
    {
        cout << sum << '\n';
        return;
    }
    else
    {
        ans -= sum;
        ans /= 2;
        ans += sum;
        cout << ans << '\n';
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
