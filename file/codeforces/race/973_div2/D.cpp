#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
vector<ll> a;
bool check1(ll x)
{
    vector<ll> b = a;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (b[i] > x)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        if (b[i] > x)
        {
            b[i + 1] += b[i] - x;
        }
    }
}
bool check2(ll x)
{
    vector<ll> b = a;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            if (b[i] >= x)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (b[i] < x)
        {
            b[i - 1] -= x - b[i];
        }
    }
}
void solve()
{
    cin >> n;
    ll x;
    a.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    ll l = 1, r = 1e12;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check1(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    ll ansl = l;
    l = 1, r = 1e12;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check2(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    ll ansr = l;
    // cout << "! " << ansl << ' ' << ansr << '\n';
    cout << ansl - ansr << '\n';
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
