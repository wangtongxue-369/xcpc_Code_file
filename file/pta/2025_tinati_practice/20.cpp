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
    vector<string> ve;
    string s;
    while (cin >> s)
    {
        if (s == ".")
        {
            break;
        }
        ve.push_back(s);
    }
    if (ve.size() >= 14)
    {
        cout << ve[1] << " and " << ve[13] << " are inviting you to dinner...";
        return;
    }
    if (ve.size() >= 2)
    {
        cout << ve[1] << " is the only one for you...";
        return;
    }
    cout << "Momo... No one is for you ...";
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
