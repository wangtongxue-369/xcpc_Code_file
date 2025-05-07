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
ll _ = 1, n, m, ans = 0, a[MAXN]; // fm[MAXN], fs[MAXN];
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{

    cin >> n;
    vector<ll> fm(n + 10, 0), fs(n + 10, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fm[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        // fm[i]=0;
        fm[i] = max(fm[i - 1], a[i]);
    }
    // fs[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        fs[i] = fs[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << fs[n - i + 1] + fm[n - i] << ' ';
    }
    cout << '\n';
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