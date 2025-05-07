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
bool bet(int i, int j, int n)
{
    if (j == 1 && i == n)
        return true;
    if (i == 1 && j == n)
        return false;
    return j > i;
}
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a, b, vis(n + 10);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            a.push_back(i + 1);
        }
        else
        {
            b.push_back(i + 1);
        }
    }
    for (auto it : a)
    {
        bool flag = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (bet(it, b[i], n))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        else
        {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
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