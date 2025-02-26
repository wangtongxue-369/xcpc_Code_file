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
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll bad = 0;
    for (int x = 1; x <= 10; x++)
    {
        map<ll, ll> ma;
        //<=k的+1，>k的减一
        // 如果出现等于零的区间，那么一定是不合法区间
        vector<ll> p;

        ll cnt = 0;
        p.push_back(cnt);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == x)
            {
                for (auto it : p)
                {
                    ma[it]++;
                }
                p.clear();
            }
            if (a[i] <= x)
            {
                cnt++;
                p.push_back(cnt);
            }
            else
            {
                cnt--;
                p.push_back(cnt);
            }
            bad += ma[cnt];
        }
    }
    cout << n * (n + 1) / 2 - bad << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
