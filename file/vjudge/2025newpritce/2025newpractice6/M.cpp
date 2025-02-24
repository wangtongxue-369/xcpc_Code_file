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
ll _ = 1, n, a[MAXN], f[MAXN];
void solve()
{
    string s;
    cin >> s;
    cin >> n;
    ll len = s.length();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]--;
        ll ans = a[i] % len;
        ll w = 0;
        ll s1 = a[i] / len;
        while (s1 > 0)
        {
            if (s1 % 2 == 1)
            {
                w++;
            }
            s1 /= 2;
        }
        if (w % 2 == 1)
        {
            if ('A' <= s[ans] && s[ans] <= 'Z')
            {
                cout << (char)(s[ans] - 'A' + 'a') << ' ';
            }
            if ('a' <= s[ans] && s[ans] <= 'z')
            {
                cout << (char)(s[ans] - 'a' + 'A') << ' ';
            }
        }
        else
        {
            cout << s[ans] << ' ';
        }
    }
    cout << '\n';
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
