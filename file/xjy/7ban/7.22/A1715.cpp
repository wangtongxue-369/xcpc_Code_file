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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    char a[1000];
    cin >> a;
    ll len = 0;
    while (a[len] != '\0')
    {
        len++;
    }
    len--;
    for (int i = 0; i <= len / 2; i++)
    {
        if (a[i] == a[len - i])
        {
            continue;
        }
        else
        {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}