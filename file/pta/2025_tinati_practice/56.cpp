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
set<int> s[55];
void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        while (m--)
        {
            int num;
            cin >> num;
            s[i].insert(num);
        }
    }

    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        set<int>::iterator it;
        int cnta = s[a].size(), cntb = s[b].size(), cnt = 0;
        for (it = s[a].begin(); it != s[a].end(); it++)
        {
            if (s[b].find(*it) != s[b].end())
                cnt++;
        }
        printf("%.2lf%\n", cnt * 1.0 / (cnta + cntb - cnt) * 100);
    }
    return;
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
