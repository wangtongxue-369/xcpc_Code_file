#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
const ll N = 1e6;
void init()
{
    vector<ll> ve;
    for (int i = 2; i <= N; i++)
    {
        if (f[i] == 0)
        {
            ve.push_back(i);
            f[i] = 1;
        }
        for (int it : ve)
        {
            if (i * it > N)
            {
                break;
            }
            f[i * it] = f[i] + 1;
            if (i % it == 0)
            {
                break;
            }
        }
    }
}
void solve()
{
    ll cnt = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (f[i] % 2)
        {
            cout << i << ' ';
            cnt++;
        }
        if (cnt == n / 2)
        {
            cout << '\n';
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    init();
    while (_--)
    {
        solve();
    }
    return 0;
}