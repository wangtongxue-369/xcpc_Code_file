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
char c[] = {'G', 'P', 'L', 'T'};
void solve()
{
    string s;
    cin >> s;
    map<char, ll> ma;
    for (auto it : s)
    {
        if ('a' <= it && it <= 'z')
        {
            ma[it - ('a' - 'A')]++;
        }
        else
        {
            ma[it]++;
        }
    }
    while (1)
    {
        ll x = 0;
        for (int i = 0; i < 4; i++)
        {
            if (ma[c[i]])
            {
                x++;
                cout << c[i];
                ma[c[i]]--;
            }
        }
        if (x == 0)
        {
            break;
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
