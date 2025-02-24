#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld 0x3f
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m; // ans=0,a[500005],f[500005];
void solve()
{
    stack<int> ans;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '#')
            {
                ans.push(i + 1);
                continue;
            }
        }
    }

    while (ans.size())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
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
