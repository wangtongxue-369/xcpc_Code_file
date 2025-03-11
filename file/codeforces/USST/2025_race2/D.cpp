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
bool cmp(PII s1, PII s2)
{
    if (s1.first == s2.first)
    {
        return s1.second < s2.second;
    }
    return s1.first < s2.first;
}
void solve()
{
    cin >> n;
    ll l, r;
    vector<PII> ve;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        ve.emplace_back(l, r);
    }
    ans = 0;
    sort(ve.begin(), ve.end(), cmp);
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll nexti = 0, x = -1;
    while (1)
    {
        while (!q.empty() && q.top() < x)
        {
            q.pop();
        }
        if (!q.empty())
        {
            ans++;
            q.pop();
            x++;
        }
        else
        {
            if (nexti <= n - 1)
            {
                x = ve[nexti].first;
            }
            else
            {
                break;
            }
        }
        while (nexti <= n - 1 && ve[nexti].first <= x)
        {
            q.push(ve[nexti].second);
            nexti++;
        }
    }
    cout << ans << '\n';
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
