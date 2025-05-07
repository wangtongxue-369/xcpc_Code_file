#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 300005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], pref[MAXN], mi[MAXN], mx[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[0] = 0;
    f[n + 1] = 0;
    f[n + 2] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= k)
        {
            f[i] = -1;
        }
        else
        {
            f[i] = 1;
        }
    }
    pref[0] = 0, pref[1] = 0, pref[n] = 0, pref[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + f[i];
    }
    if (*min_element(pref + 1 + 1, pref + 1 + n - 1) < 0)
    {
        // 偶数为 0 时，如果再来一个-1 那么成为奇数 最中间一定为-1
        cout << "YES\n";
        return;
    }
    if (std::count(pref + 1 + 1, pref + 1 + n - 1, 0) >= 2)
    {
        // 两次0 选这个区间
        // 两个之间一定为偶区间 -1成立
        cout << "YES\n";
        return;
    }
    if (*std::max_element(pref + 1, pref + n - 1) > pref[n])
    {
        // 最大值大于之后的 -1多于 1
        cout << "YES\n";
        return;
    }
    if (count(pref + 1, pref + n - 1, pref[n]) >= 2)
    {

        cout << "YES\n";
        return;
    }
    // 左右区间都-1成立
    ll l = 1, r = n - 1;
    while (l < r && pref[l] > 0)
    {
        l++;
    }
    while (l < r && pref[r] < pref[n])
    {
        r--;
    }
    if (l < r)
    {
        cout << "YES\n";
        return;
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