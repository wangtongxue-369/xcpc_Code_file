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
    string c;
    cin >> c;
    string s;
    char c1;
    cin.get(c1);
    getline(cin, s);
    // cout << s << '\n';
    if (n >= s.length())
    {
        ll p = n - s.length();
        // cout << p << '\n';
        while (p--)
        {
            cout << c;
        }
        cout << s << '\n';
    }
    else
    {
        for (int i = s.length() - n; i < s.length(); i++)
        {
            cout << s[i];
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
