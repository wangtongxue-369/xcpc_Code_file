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
    cin >> n;
    ll shi = 0, xu = 0;
    ll s1, s2;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2;
        shi += s1;
        xu += s2;
    }
    if (shi == 0 && xu == 0)
    {
        cout << 0 << '\n';
        return;
    }
    if (shi != 0)
    {
        cout << shi;
    }
    if (xu > 0)
    {
        if (shi != 0)
        {
            cout << '+';
        }
        if (xu == 1)
        {
            cout << "i\n";
        }
        else
        {
            cout << xu << "i\n";
        }
    }
    else if (xu < 0)
    {
        if (xu == -1)
        {
            cout << "-i\n";
        }
        else
        {
            cout << xu << "i\n";
        }
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
