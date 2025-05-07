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
ll _ = 1, n, m; // a[MAXN], f[MAXN];
ll p0;
struct node
{
    ll num, p;
    bool operator<(const node &other) const
    {
        if (num == other.num)
        {
            if (p > p0 && other.p > p0)
            {
                return p > other.p;
            }
            return p < other.p;
        }
        return num < other.num;
    }
};
void solve()
{
    cin >> n;
    vector<node> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num;
        a[i].p = i;
        if (a[i].num == -1)
        {
            p0 = i;
        }
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    vector<ll> ans(n + 10);
    ll l = 1, r = n;
    // cout << a[1].num << '\n';
    for (int i = 2; i <= n; i++)
    {
        if (a[i].num % 2)
        {
            ans[a[i].p] = r;
            r--;
        }
        else
        {
            ans[a[i].p] = l;
            l++;
        }
    }
    ans[a[1].p] = r;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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