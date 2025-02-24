#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a, b, c;
void solve()
{
    cin >> a >> b >> c;
    m = 1;
    // unordered_map<ll, ll> ma;
    vector<bool> ma(1e9 + 10);
    ma[m] = 1;
    for (int i = 1; i <= 2000000; i++)
    {
        m = (m * a + m % b) % c;
        // cout << m << ' ';
        if (ma[m] == 1)
        {
            cout << i << '\n';
            return;
        }
        ma[m] = 1;
    }
    cout << "-1" << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
