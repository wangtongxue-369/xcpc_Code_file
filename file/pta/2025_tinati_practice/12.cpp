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
ll _ = 1, n, m, ans = 0;
string a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    set<string> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
            if (m >= 2)
            {
                se.insert(a[j]);
            }
        }
    }
    cin >> n;
    string x;
    bool flag = 1;
    string s;
    while (n--)
    {
        cin >> x;
        if (se.contains(x))
        {
            continue;
        }
        else
        {
            flag = 0;
            s += x + ' ';
            se.insert(x);
        }
    }
    if (flag)
    {
        cout << "No one is handsome";
    }
    else
    {
        for (int i = 0; i < s.length() - 1; i++)
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
