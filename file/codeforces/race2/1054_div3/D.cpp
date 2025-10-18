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
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a, b;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            a.push_back(i + 1);
        }
        else
        {
            b.push_back(i + 1);
        }
    }
    ans = 1e18;
    // a先放一个地 b再放完 a放剩下的

    ll mida = (a.size() + 1) / 2 - 1;
    ll midb = (b.size() + 1) / 2 - 1;
    ll an1 = 0, an2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        an1 += abs(a[i] - i - a[mida] + mida);
    }
    for (int i = 0; i < b.size(); i++)
    {
        an2 += abs(b[i] - i - b[midb] + midb);
    }
    cout << min(an1, an2) << '\n';
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