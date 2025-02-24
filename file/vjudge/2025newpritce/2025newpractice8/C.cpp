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
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
        {
            continue;
        }
        else if ((s1[i] == '0' && s2[i] == 'o') || (s1[i] == 'o' && s2[i] == '0'))
        {
            continue;
        }
        else if ((s1[i] == 'l' && s2[i] == '1') || (s1[i] == '1' && s2[i] == 'l'))
        {
            continue;
        }
        else
        {
            cout << "No\n";
            return;
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
