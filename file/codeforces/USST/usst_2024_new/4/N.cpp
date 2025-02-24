#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m;
vector<ll> a(MAXN + 100, 0);
vector<ll> v(MAXN + 100, 0);
vector<ll> x(MAXN + 100, 0);
vector<ll> t(MAXN + 100, 0);
void solve()
{
    cin >> n >> m;
    queue<ll> cd[n + 10];
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[i] = a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> t[i];
        cd[t[i]].push(x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cd[i].push(1e18);
    }
    ans = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 1; i <= n; i++)
    {
        if (cd[i].size() > 0)
        {
            ll s = cd[i].front();
            cd[i].pop();
            q.emplace(s, i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        // cout << "!1" << '\n';
        ll len = x[i] - x[i - 1];
        while (len > 0)
        {
            // cout << "!2" << '\n';
            if (!q.empty())
            {
                // cout << "!3" << '\n';
                // auto [x1, i1] = q.top();
                ll x1, i1;
                q.pop();
                if (v[i1] == 0)
                {
                    continue;
                }

                if (v[i1] <= len)
                {
                    len -= v[i1];
                    v[i1] = 0;
                }
                else // v[i1]>len
                {
                    v[i1] -= len;
                    len = 0;
                    q.emplace(x1, i1);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (len > 0)
        {
            // cout << "!5" << '\n';
            ans += (x[i] - x[i - 1]) - len;
            break;
        }
        else
        {
            // cout << "!6" << '\n';
            v[t[i]] = a[t[i]];
            ll fi = 1e18, ti = t[i];
            if (cd[t[i]].size() > 0)
            {
                fi = cd[t[i]].front();
                cd[t[i]].pop();
            }
            if (!q.empty())
            {
                if (q.top().second == ti)
                {
                    q.pop();
                }
            }
            q.emplace(fi, ti);
            ans += x[i] - x[i - 1];
        }
    }
    // cout << "!7" << '\n';
    for (int i = 1; i <= n; i++)
    {
        ans += v[i];
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
// 最少走sum
// 遇到一个加油站时，
// sum a[i] t;
// ans+x;
//
