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
    string s1 = "nowcoder";
    map<ll, ll> ma;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        ma[s[i]]++;
    }
    if (ma[99] == 1 && ma[100] == 1 && ma[101] == 1 && ma[110] == 1 && ma[111] == 2 && ma[114] == 1 && ma[119] == 1)
    {
        cout << "happy new year\n";
    }
    else
    {
        cout << "I AK IOI\n";
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
