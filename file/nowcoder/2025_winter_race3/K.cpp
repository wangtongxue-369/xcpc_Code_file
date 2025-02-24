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
ll _ = 1, n, m[MAXN], ans = 0, f[MAXN], mi[MAXN];
bool cmp(vector<ll> s1, vector<ll> s2)
{
    return s1[0] > s2[0];
}
vector<ll> ve[MAXN];
void solve()
{
    ll k, x;
    map<ll, ll> ma;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        for (int j = 1; j <= m[i]; j++)
        {
            cin >> x;
            ve[i].push_back(x);
            ma[x] = i;
        }
    }
    ll sumn = 0, len = 0;
    vector<ll> a;
    sort(ve + 1, ve + n + 1, cmp);

    // cout << k1 << ' ' << len << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < ve[i].size(); j++)
        {
            a.push_back(ve[i][j]);
        }
    }
    ll k1 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] > a[j])
            {
                k1++;
            }
        }
    }
    // cout << k1 << '\n';
    if (k1 < k)
    {
        cout << "No\n";
        return;
    }
    // cout << k1 << '\n';
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j + 1 < a.size(); j++)
        {
            if (ma[a[j]] == ma[a[j + 1]])
            {
                continue;
            }
            if (k1 > k && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                k1--;
            }
        }
    }
    // cout << k1 << '\n';
    if (k1 > k)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (auto it : a)
    {
        cout << it << ' ';
    }
    cout << '\n';
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
