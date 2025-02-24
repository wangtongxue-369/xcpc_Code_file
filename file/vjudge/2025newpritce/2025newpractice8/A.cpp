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
    cin >> n;
    string s;
    cin >> s;
    ll sa = 0, sb = 0;
    for (auto it : s)
    {
        if (it == 'T')
        {
            sa++;
        }
        else
        {
            sb++;
        }
        if (sa >= ceil(1.0 * n / 2))
        {
            cout << "T\n";
            return;
        }
        else if (sb >= ceil(1.0 * n / 2))
        {
            cout << "A\n";
            return;
        }
    }
    if (sa >= sb)
    {
        cout << "T\n";
        return;
    }
    else
    {
        cout << "A\n";
        return;
    }
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
