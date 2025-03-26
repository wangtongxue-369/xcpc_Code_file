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
bool cmp(vector<ll> s1, vector<ll> s2)
{
    if (s1.size() == s2.size())
    {
        return s1[0] < s2[0];
    }
    return s1.size() > s2.size();
}
void solve()
{
    vector<vector<ll>> an;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    if (n == 2)
    {
        cout << 1 << '\n';
        cout << 2 << '\n';
        return;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            vector<ll> ve;
            ll p = i, n1 = n;
            while (n1 % p == 0)
            {
                ve.push_back(p);
                n1 /= p;
                p++;
            }
            an.push_back(ve);
        }
    }
    sort(an.begin(), an.end(), cmp);
    if (an.size() == 0)
    {
        cout << 1 << '\n';
        cout << n << '\n';
        return;
    }
    cout << an[0].size() << '\n';
    for (int i = 0; i < an[0].size(); i++)
    {
        cout << an[0][i] << "*\n"[i == an[0].size() - 1];
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
