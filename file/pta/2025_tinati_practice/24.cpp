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
    ll p = 1;
    ans = 0;
    string s;
    ll sum = 1;
    while (p != 0)
    {
        sum++;
        p *= 10;
        p += 1;
        s += to_string(p / n);
        p = p % n;
    }
    bool flag = 1;
    for (auto it : s)
    {
        if (flag)
        {
            if (it == '0')
            {
                continue;
            }
            else
            {
                cout << it;
                flag = 0;
            }
        }
        else
        {
            cout << it;
        }
    }
    // cout << s;
    cout << ' ' << sum;
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
