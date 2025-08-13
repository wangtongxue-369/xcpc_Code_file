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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    ll totsize = 0;
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    ll pos = n / 2;
    map<ll, ll> ma;
    for (int i = n - pos + 1; i <= n; i++)
    {
        totsize++;
        ma[b[i]]++;
    }
    ll po = n - pos;
    while (po > 0 && b[po] == b[n - pos + 1])
    {
        totsize++;
        ma[b[po]]++;
        po--;
    }
    // for (auto it : ma)
    // {
    //     cout << it.first << ' ' << it.second << '\n';
    // }
    // cout << '\n';
    ll p, v;
    while (q--)
    {
        cin >> p >> v;
        ll to = (*ma.begin()).first;
        if (a[p] < to)
        {
            if (a[p] + v < to)
            {
                a[p] += v;
            }
            else if (a[p] + v == to)
            {
                a[p] += v;
                totsize++;
                (*ma.begin()).second++;
            }
            else if (a[p] + v > to)
            {
                a[p] += v;
                if (totsize + 1 - (*ma.begin()).second >= pos)
                {
                    totsize++;
                    totsize -= (*ma.begin()).second;
                    ma.erase(ma.begin());
                    ma[a[p]]++;
                }
                else
                {
                    totsize++;
                    ma[a[p]]++;
                }
            }
        }
        else
        {
            if (a[p] == to)
            {
                if (totsize - (*ma.begin()).second + 1 >= pos)
                {
                    // cout << "!!! ";
                    totsize -= ((*ma.begin()).second);
                    totsize++;
                    ma.erase(ma.begin());
                    ma[a[p] + v]++;
                    a[p] += v;
                }
                else
                {
                    (*ma.begin()).second--;
                    if ((*ma.begin()).second == 0)
                    {
                        ma.erase(ma.begin());
                    }
                    ma[a[p] + v]++;
                    a[p] += v;
                }
            }
            else
            {
                if (ma[a[p]] == 1)
                {
                    ma.erase(ma.find(a[p]));
                    ma[a[p] + v]++;
                    a[p] += v;
                }
                else
                {
                    ma[a[p]]--;
                    ma[a[p] + v]++;
                    a[p] += v;
                }
            }
        }

        cout << n - totsize << '\n';

        // for (auto it : ma)
        // {
        //     cout << it.first << ' ' << it.second << '\n';
        // }
        // cout << '\n';
    }
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