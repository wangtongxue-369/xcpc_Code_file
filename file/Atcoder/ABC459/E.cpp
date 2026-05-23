/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, d[MAXN], c[MAXN];
ll fa[MAXN];
ll sy[MAXN];
vector<ll> fact, invfact;
ll ksm(ll a, ll e)
{
    ll r = 1;
    while (e > 0)
    {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
void init_comb(int maxD)
{
    fact.assign(maxD + 1, 1);
    invfact.assign(maxD + 1, 1);

    for (int i = 1; i <= maxD; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    invfact[maxD] = ksm(fact[maxD], mod - 2);

    for (int i = maxD; i >= 1; i--)
    {
        invfact[i - 1] = invfact[i] * i % mod;
    }
}

ll C(ll n, int k)
{
    if (n < k)
        return 0;

    ll m = n % mod;
    if (m < k)
        return 0;

    ll res = 1;
    for (int i = 0; i < k; i++)
    {
        res = res * (m - i) % mod;
    }

    res = res * invfact[k] % mod;
    return res;
}
void solve()
{
    ans = 1;
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    ll x;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        ve[x].push_back(i);
        fa[i] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        maxn = max(maxn, d[i]);
    }
    init_comb(maxn);
    stack<ll> st;
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        st.push(x);
        for (auto it : ve[x])
        {
            q.push(it);
        }
    }
    while (!st.empty())
    {
        ll v = st.top();
        st.pop();
        ll cnt = c[v];
        for (auto to : ve[v])
        {
            cnt += sy[to];
        }

        if (cnt < d[v])
        {
            cout << 0 << '\n';
            return;
        }

        ans = ans * C(cnt, d[v]) % mod;
        sy[v] = cnt - d[v];
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}