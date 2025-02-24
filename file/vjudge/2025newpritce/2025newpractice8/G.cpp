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
string s = "atcoder";
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    map<ll, ll> ma;
    ll sum1 = 0, sum2 = 0;
    for (auto it : s1)
    {
        if (it == '@')
        {
            sum1++;
            continue;
        }
        ma[it]++;
    }
    for (auto it : s2)
    {
        if (it == '@')
        {
            sum2++;
            continue;
        }
        ma[it]--;
    }
    for (auto [x, w] : ma)
    {
        if (w)
        {
            if (x == 'a' || x == 't' || x == 'c' || x == 'o' || x == 'd' || x == 'e' || x == 'r')
            {
                if (w > 0)
                {
                    if (sum2 >= w)
                    {
                        sum2 -= w;
                    }
                    else
                    {
                        cout << "No\n";
                        return;
                    }
                }
                else if (w < 0)
                {
                    w = w * -1;
                    if (sum1 >= w)
                    {
                        sum1 -= w;
                    }
                    else
                    {
                        cout << "No\n";
                        return;
                    }
                }
            }
            else
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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
