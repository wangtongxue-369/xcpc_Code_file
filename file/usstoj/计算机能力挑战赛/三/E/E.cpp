#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    set<string> se;
    for (int i = 0; i < s.length() - 1; i++)
    {
        string s1 = s.substr(i, 2);
        se.insert(s1);
    }
    cout << se.size() << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
