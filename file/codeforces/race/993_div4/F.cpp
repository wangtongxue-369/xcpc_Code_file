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
    ll q;
    cin >> n >> m >> q;
    ll suma = 0, sumb = 0;
    map<ll, ll> ma, mb;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i], suma += a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i], sumb += b[i];
    }
    // sort(a + 1, a + 1 + n);
    //  sum-x;   需要减掉的
    //  sum-x=a[i]*sumb+b[i]*suma-a[i]*b[i];
    //        a[i]*(sumb-b[i])+b[i]*suma;
    //  suma*sumb-x=a[i]*(sumb-b[i])+b[i]*suma;
    //  suma*sumb-a[i]*(sumb-b[i])-b[i]*suma=x
    //  suma*(sumb-b[i])-a[i]*(sumb-b[i])=x;
    //  (suma-a[i])*(sumb-b[i])=x
    for (int i = 1; i <= n; i++)
    {
        ma[suma - a[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        mb[sumb - b[i]] = 1;
    }
    ll x;
    while (q--)
    {
        cin >> x;
        bool flag = 0;
        if (x == 0)
        {
            if (ma.count(x) || mb.count(x))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }
        for (ll i = 1; i * i <= abs(x); i++)
        {
            if (x % i == 0)
            {
                ll j = x / i;
                if ((ma.count(i) && mb.count(j)) || (ma.count(j) && mb.count(i)))
                {
                    flag = 1;
                    break;
                }
                else if (ma.count(-1 * i) && mb.count(-1 * j) || (ma.count(-1 * j) && mb.count(-1 * i)))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
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
