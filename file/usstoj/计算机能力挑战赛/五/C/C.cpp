#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // a[N], f[N];
string a[N];
bool cmp(string s1, string s2)
{
    ll s1y = (s1[6] - '0') * 1000 + (s1[7] - '0') * 100 + (s1[8] - '0') * 10 + (s1[9] - '0');
    ll s1m = (s1[10] - '0') * 10 + s1[11] - '0';
    ll s1d = (s1[12] - '0') * 10 + s1[13] - '0';
    ll s2y = (s2[6] - '0') * 1000 + (s2[7] - '0') * 100 + (s2[8] - '0') * 10 + (s2[9] - '0');
    ll s2m = (s2[10] - '0') * 10 + s2[11] - '0';
    ll s2d = (s2[12] - '0') * 10 + s2[13] - '0';
    if (s1y == s2y)
    {
        if (s1m == s2m)
        {
            if (s1d == s2d)
            {
                return s1 > s2;
            }
            return s1d > s2d;
        }
        return s1m > s2m;
    }
    return s1y > s2y;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << '\n';
    }
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
