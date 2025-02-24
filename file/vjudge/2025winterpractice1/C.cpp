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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    ll na, nb;
    cin >> n >> na >> nb;
    int ma[5][5] =
        {
            {0, -1, 1, 1, -1},
            {1, 0, -1, 1, -1},
            {-1, 1, 0, -1, 1},
            {-1, -1, 1, 0, 1},
            {1, 1, -1, -1, 0}};
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++)
    {
        cin >> b[i];
    }
    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; i++)
    {
        if (ma[a[i % na]][b[i % nb]] == 1)
        {
            suma++;
        }
        else if (ma[a[i % na]][b[i % nb]] == -1)
        {
            sumb++;
        }
    }
    cout << suma << ' ' << sumb << '\n';
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
