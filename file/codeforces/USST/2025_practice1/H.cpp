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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];

void solve()
{
    string s;
    cin >> s;
    n = s.length();
    ll nsb;
    string sb;
    sb = "chimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "tte\n";
            return;
        }
    }
    sb = "rimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "tte\n";
            return;
        }
    }
    sb = "mimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "nde\n";
            return;
        }
    }
    sb = "bimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "nde\n";
            return;
        }
    }
    sb = "nimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "nde\n";
            return;
        }
    }
    sb = "kimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            if (s == "ikimasu")
            {
                cout << "itte\n";
            }
            else
            {
                cout << s.substr(0, (n - nsb)) << "ite\n";
            }

            return;
        }
    }
    sb = "gimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "ide\n";
            return;
        }
    }
    sb = "shimasu";
    nsb = sb.length();
    if (s.length() >= sb.length())
    {
        if (s.substr(n - nsb) == sb)
        {
            cout << s.substr(0, (n - nsb)) << "shite\n";
            return;
        }
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
