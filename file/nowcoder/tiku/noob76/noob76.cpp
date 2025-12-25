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
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    vector<ll> ve;
    while (n--)
    {
        ll op;
        cin >> op;
        ll x;
        if (op == 1)
        {
            cin >> x;
            ve.push_back(x);
        }
        else if (op == 2)
        {
            ve.pop_back();
        }
        else if (op == 3)
        {
            cin >> x;
            cout << ve[x] << '\n';
        }
        else if (op == 4)
        {
            ll p, x;
            cin >> p >> x;
            stack<ll> st;
            while (ve.size() > p + 1)
            {
                st.push(ve.back());
                ve.pop_back();
            }
            ve.push_back(x);
            while (st.size())
            {
                ve.push_back(st.top());
                st.pop();
            }
        }
        else if (op == 5)
        {
            sort(ve.begin(), ve.end());
        }
        else if (op == 6)
        {
            sort(ve.begin(), ve.end(), greater<ll>());
        }
        else if (op == 7)
        {
            cout << ve.size() << '\n';
        }
        else if (op == 8)
        {
            for (auto it : ve)
            {
                cout << it << ' ';
            }
            cout << '\n';
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