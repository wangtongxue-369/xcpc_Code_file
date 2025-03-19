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
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // if (k==2)
    //{
    //  na 3 ge
    //  一定可以有一个夹在中间 然后最后一次拿到
    //}
    function<bool(ll, ll)> cmp = [&](ll s1, ll s2)
    {
        return s1 > s2;
    };
    if (k == 1)
    {
        ll maxn = a[1], pos = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > maxn)
            {
                maxn = max(maxn, a[i]);
                pos = i;
            }
        }
        if (pos == 1 || pos == n)
        {
            sort(a + 1, a + 1 + n, cmp);
            cout << a[1] + a[2] << '\n';
        }
        else
        {
            cout << max(a[1], a[n]) + a[pos] << '\n';
        }
        return;
    }

    sort(a + 1, a + 1 + n, cmp);
    ll sum = 0;
    for (int i = 1; i <= k + 1; i++)
    {
        sum += a[i];
    }
    cout << sum << '\n';
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
