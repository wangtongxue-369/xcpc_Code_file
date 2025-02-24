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
    ll sumA = 0, sumB = 0, sumC = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '2')
        {
            sumC++;
            continue;
        }
        if (i % 2 == 1)
        {
            if (s[i] == '0')
            {
                sumA++;
            }
            else
            {
                sumB++;
            }
        }
        else
        {
            if (s[i] == '0')
            {
                sumB++;
            }
            else
            {
                sumA++;
            }
        }
    }
    ll t = abs(sumA - sumB);
    if (t <= sumC)
    {
        if (n % 2 == 1)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
            return;
        }
    }
    else
    {
        cout << t - sumC << '\n';
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
