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
ll k;
ll p = 1;

void solve()
{
    cin >> n;
    vector<ll> ve;
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        ve.push_back(i);
    }
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << ve[i] << ' ';
        }
        cout << "! ";
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll minn = 1e18;
            for (int j = i; j < n; j++)
            {
                minn = min(minn, ve[j]);
                sum += minn;
            }
        }
        maxn = max(maxn, sum);
        cout << sum << '\n';

    } while (next_permutation(ve.begin(), ve.end()));
    ll p = 1;
    do
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll minn = 1e18;
            for (int j = i; j < n; j++)
            {
                minn = min(minn, ve[j]);
                sum += minn;
            }
        }
        if (sum == maxn)
        {
            cout << "! " << p << ' ';
            for (auto it : ve)
            {
                cout << it << ' ';
            }
        }
        cout << '\n';
        p++;

    } while (next_permutation(ve.begin(), ve.end()));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    f[1] = 1;
    for (int i = 1;; i++)
    {
        f[i + 1] = f[i] * i;
        if (f[i + 1] > 1e12)
        {
            break;
        }
    }
    while (_--)
    {
        solve();
    }
    return 0;
}
