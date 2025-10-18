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
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, tr[MAXN];
ll lowbit(ll x)
{
    return x & (-x);
}

void add(ll x, ll v)
{
    while (x <= n)
    {
        tr[x] ^= v;
        x += lowbit(x);
    }
}
ll sum(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans ^= tr[x];
        x -= lowbit(x);
    }
    return ans;
}
ll get(ll l, ll r)
{
    ll ans1 = 0;
    l--;
    while (l)
    {
        ans1 ^= tr[l];
        l -= lowbit(l);
    }
    ll ans2 = 0;
    while (r)
    {
        ans2 ^= tr[r];
        r -= lowbit(r);
    }
    return ans2 ^ ans1;
}
void solve()
{
    ll a, b;
    ll q;
    cin >> n >> q;
    mt19937 myrand(time(nullptr));
    while (q--)
    {
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        if (get(a, b) == 0)
        {
            ll p = myrand() % 100000000;
            add(a, p), add(b, p);
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
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