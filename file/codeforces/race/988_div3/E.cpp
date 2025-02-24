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
ll _ = 1, n, m;
ll ask(ll l, ll r)
{
    cout << "? " << l << ' ' << r << endl;
    ll res;
    cin >> res;
    return res;
}
void no()
{
    cout << "! IMPOSSIBLE" << endl;
}
void solve()
{
    cin >> n;
    ll pp = 0, p = 0;
    string s;
    ll sum0 = 0;
    for (int i = 1; i < n; i++)
    {
        p = ask(1, i + 1);
        if (pp == 0)
        {
            if (p == 0)
            {
                continue;
            }
            else if (p > i)
            {
                no();
                return;
            }
            for (int j = 1; j <= i - p; j++)
            {
                s += '1';
            }
            for (int j = 1; j <= p; j++)
            {
                s += '0';
            }
            sum0 = p;
            pp = p;
            s += '1';
        }
        else
        {
            if (p == pp)
            {
                s += '0';
                sum0++;
                continue;
            }
            else if (p > pp)
            {
                if (p - pp == sum0)
                {
                    s += '1';
                    '1';
                    pp = p;
                    continue;
                }
                else
                {
                    no();
                    return;
                }
            }
            else
            {
                no();
                return;
            }
        }
    }
    if (s.length() != n)
    {
        no();
        return;
    }
    cout << "! " << s << endl;
    cout.flush();
}
signed main()
{
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
