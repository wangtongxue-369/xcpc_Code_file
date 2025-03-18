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
    string s, k;
    cin >> s >> k;
    m = 0;
    for (int i = 0; i < k.size(); i++)
    {
        m = m * 10 + k[i] - '0';
        if (m > 26)
        {
            m = 26;
            break;
        }
    }
    string s1;
    for (int i = 1; i <= m; i++)
    {
        s1 += s;
    }
    vector<char> tails;
    for (auto num : s1)
    {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end())
        {
            tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }
    cout << tails.size() << '\n';
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
