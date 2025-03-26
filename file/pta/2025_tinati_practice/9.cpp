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
ll _ = 1, n, ans = 0, a[MAXN], f[MAXN];
ll w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
void solve()
{
    bool flag = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        ll sum = 0;
        for (int j = 0; j < 17; j++)
        {
            sum += (s[j] - '0') * w[j];
        }
        if (s[17] != m[sum % 11])
        {
            cout << s << '\n';
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "All passed\n";
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
