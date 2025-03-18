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
string s1[] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
string s2[] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
map<string, ll> ma;
void solve()
{
    string s;
    cin >> s;
    cout << ma[s] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll p = 1984;
    ll p1 = 0, p2 = 0;
    for (int i = 1984; i <= 2043; i++)
    {
        ma[s1[p1 % 10] + s2[p2 % 12]] = i;
        p1++, p2++;
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
